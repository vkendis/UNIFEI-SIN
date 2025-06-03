from model import TipoNutriEcoScoreDB, TipoNovaScoreDB

def sanitize_enum_value(value, enum_cls):
    try:
        return enum_cls(value.upper())
    except Exception:
        return None

def transform_api_data(api_data: dict, product_code: str):
    try:
        transformed = {
            "codigo": product_code,
            "nome": api_data.get("product_name", "NOME_DESCONHECIDO"),
            "nutriscore": sanitize_enum_value(api_data.get("nutriscore_grade", ""), TipoNutriEcoScoreDB),
            "ecoscore": sanitize_enum_value(api_data.get("ecoscore_grade", ""), TipoNutriEcoScoreDB),
            "novascore": sanitize_enum_value(str(api_data.get("nova_group", "")), TipoNovaScoreDB),

            "marcas": [m.strip() for m in api_data.get("brands", "").split(",") if m.strip()],
            "categorias": [c.strip() for c in api_data.get("categories", "").split(",") if c.strip()],
            "ingredientes": api_data.get("ingredients", []),
            "nutrientes": api_data.get("nutriments", {}),
            "tags": api_data.get("labels_tags", []),
        }
        return transformed
    except Exception as e:
        print(f"ERROR: Falha ao transformar os dados do produto {product_code}: {e}")
        return None
