# etl/extract.py
import requests

def fetch_product_data_from_api(product_code: str, api_base_url: str):
    url = f"{api_base_url}/product/{product_code}.json"
    try:
        response = requests.get(url, timeout=10)
        response.raise_for_status()
        data = response.json()
        if data.get("status") != 1:
            print(f"WARN: Produto {product_code} não encontrado na API.")
            return None
        return data.get("product")
    except requests.RequestException as e:
        print(f"ERROR: Falha ao buscar dados da API para {product_code}: {e}")
        return None
