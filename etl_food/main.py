# main.py
import traceback
import json
from pathlib import Path
from sqlalchemy.orm import Session

from database import get_db_session, create_database_tables, DATABASE_URL
import model
from etl import extract, transform, load

API_BASE_URL_PARA_EXTRACT = "https://world.openfoodfacts.net/api/v2"

def process_product_etl(product_code_to_fetch: str, db: Session, api_base_url: str):
    print(f"INFO: Iniciando ETL para o código: {product_code_to_fetch}")
    
    api_data = extract.fetch_product_data_from_api(product_code_to_fetch, api_base_url)
    if not api_data:
        print(f"ERROR: Falha na extração para {product_code_to_fetch}")
        return False

    transformed_data = transform.transform_api_data(api_data, product_code_to_fetch)
    if not transformed_data:
        print(f"ERROR: Falha na transformação para {product_code_to_fetch}")
        return False

    try:
        load.load_data_to_db(db, transformed_data)
        return True
    except Exception as e: 
        print(f"ERROR: Erro ao carregar dados do produto {product_code_to_fetch}: {e}")
        traceback.print_exc()
        return False

def run_etl_pipeline():
    create_database_tables()

    # Caminho para o arquivo JSON
    json_path = Path("product_codes_dict.json")

    # Carregar códigos do arquivo JSON
    with open(json_path, "r", encoding="utf-8") as f:
        product_codes_json = json.load(f)
        product_codes = [str(item["code"]) for item in product_codes_json]

    db_session = get_db_session()
    db: Session = next(db_session)

    for code in product_codes:
        try:
            success = process_product_etl(code, db, API_BASE_URL_PARA_EXTRACT)
            if success:
                db.commit()
                print(f"INFO: COMMIT realizado com sucesso para o produto: {code}")
            else:
                db.rollback()
                print(f"WARN: ROLLBACK realizado para o produto: {code}")
        except Exception as e:
            print(f"ERROR: Erro inesperado com o produto {code}: {e}")
            traceback.print_exc()
            db.rollback()
        finally:
            print(f"INFO: Finalizado o ETL para o código: {code}")

    try:
        next(db_session)  # Fecha o generator
    except StopIteration:
        pass

if __name__ == "__main__":
    run_etl_pipeline()
