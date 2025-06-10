import re
from sqlalchemy.orm import Session
from model import (
    Produto, Marca, Nutriente, Ingrediente, Tag, Categoria,
    ProdutoMarca, ProdutoIngrediente, ProdutoNutriente,
    ProdutoTag, ProdutoCategoria
)

def sanitize_text(texto, max_len=None, only_ascii=False):
    if not isinstance(texto, str):
        texto = str(texto or "")
    texto = texto.strip()
    if only_ascii:
        texto = re.sub(r'[^\x00-\x7F]+', '', texto)
    if max_len:
        return texto[:max_len]
    return texto

def load_data_to_db(db: Session, data: dict):
    # Verifica se o produto já existe
    if db.query(Produto).filter_by(codigo=data["codigo"]).first():
        print(f"WARN: Produto {data['codigo']} já existe no banco. Pulando inserção.")
        return

    produto = Produto(
        codigo=data["codigo"],
        nome=sanitize_text(data["nome"], 255),
        nutriscore=sanitize_text(data.get("nutriscore"), 1),
        ecoscore=sanitize_text(data.get("ecoscore"), 1),
        novascore=sanitize_text(data.get("novascore"), 10),
    )
    db.add(produto)
    db.flush()

    # Marcas
    marcas_inseridas = set()
    for marca_nome in data.get("marcas", []):
        nome = sanitize_text(marca_nome, 100)
        if nome in marcas_inseridas:
            continue
        marcas_inseridas.add(nome)

        marca = db.query(Marca).filter_by(nome=nome).first()
        if not marca:
            marca = Marca(nome=nome)
            db.add(marca)
            db.flush()
        if not db.query(ProdutoMarca).filter_by(produto_id=produto.codigo, marca_id=marca.id).first():
            db.add(ProdutoMarca(produto_id=produto.codigo, marca_id=marca.id))

    # Categorias
    categorias_inseridas = set()
    for categoria_nome in data.get("categorias", []):
        nome = sanitize_text(categoria_nome, 100)
        if nome in categorias_inseridas:
            continue
        categorias_inseridas.add(nome)

        categoria = db.query(Categoria).filter_by(nome=nome).first()
        if not categoria:
            categoria = Categoria(nome=nome)
            db.add(categoria)
            db.flush()
        if not db.query(ProdutoCategoria).filter_by(produto_id=produto.codigo, categoria_id=categoria.id).first():
            db.add(ProdutoCategoria(produto_id=produto.codigo, categoria_id=categoria.id))

    # Ingredientes
    ingredientes_inseridos = set()
    for ing in data.get("ingredientes", []):
        nome = sanitize_text(ing.get("text"), 255)
        if not nome or nome in ingredientes_inseridos:
            continue
        ingredientes_inseridos.add(nome)

        ingrediente = db.query(Ingrediente).filter_by(nome=nome).first()
        if not ingrediente:
            ingrediente = Ingrediente(
                nome=nome,
                vegano=ing.get("vegan") == "yes",
                vegetariano=ing.get("vegetarian") == "yes"
            )
            db.add(ingrediente)
            db.flush()
        if not db.query(ProdutoIngrediente).filter_by(produto_id=produto.codigo, ingrediente_id=ingrediente.id).first():
            db.add(ProdutoIngrediente(produto_id=produto.codigo, ingrediente_id=ingrediente.id))

    # Nutrientes
    for nome, valor in data.get("nutrientes", {}).items():
        if not isinstance(valor, (int, float)):
            continue
        nome = sanitize_text(nome, 100)
        unidade = "g"
        nutriente = db.query(Nutriente).filter_by(nome=nome).first()
        if not nutriente:
            nutriente = Nutriente(nome=nome, unidade=unidade)
            db.add(nutriente)
            db.flush()
        if not db.query(ProdutoNutriente).filter_by(produto_id=produto.codigo, nutriente_id=nutriente.id).first():
            db.add(ProdutoNutriente(produto_id=produto.codigo, nutriente_id=nutriente.id, quantidade_100g=valor))

    # Tags
    tags_inseridas = set()
    for tag_nome in data.get("tags", []):
        nome = sanitize_text(tag_nome, 100)
        if nome in tags_inseridas:
            continue
        tags_inseridas.add(nome)

        tipo = "additive" if "add" in nome else "allergen"
        tag = db.query(Tag).filter_by(nome=nome, tipo=tipo).first()
        if not tag:
            tag = Tag(nome=nome, tipo=tipo)
            db.add(tag)
            db.flush()
        if not db.query(ProdutoTag).filter_by(produto_id=produto.codigo, tag_id=tag.id).first():
            db.add(ProdutoTag(produto_id=produto.codigo, tag_id=tag.id))

    db.flush()
