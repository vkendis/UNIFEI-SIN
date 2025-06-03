from sqlalchemy.orm import Session
from model import (
    Produto, Marca, Nutriente, Ingrediente, Tag, Categoria,
    ProdutoMarca, ProdutoIngrediente, ProdutoNutriente,
    ProdutoTag, ProdutoCategoria
)

def load_data_to_db(db: Session, data: dict):
    # Verifica se o produto já existe
    produto_existente = db.query(Produto).filter_by(codigo=data["codigo"]).first()
    if produto_existente:
        print(f"WARN: Produto {data['codigo']} já existe no banco. Pulando inserção.")
        return

    # Cria o novo produto
    produto = Produto(
        codigo=data["codigo"],
        nome=data["nome"],
        nutriscore=data.get("nutriscore"),
        ecoscore=data.get("ecoscore"),
        novascore=data.get("novascore"),
    )
    db.add(produto)
    db.flush()  # Garante que produto.codigo está disponível

    # Marcas
    for marca_nome in data["marcas"]:
        marca = db.query(Marca).filter_by(nome=marca_nome).first()
        if not marca:
            marca = Marca(nome=marca_nome)
            db.add(marca)
            db.flush()
        db.add(ProdutoMarca(produto_id=produto.codigo, marca_id=marca.id))

    # Categorias
    for categoria_nome in data["categorias"]:
        categoria = db.query(Categoria).filter_by(nome=categoria_nome).first()
        if not categoria:
            categoria = Categoria(nome=categoria_nome)
            db.add(categoria)
            db.flush()
        db.add(ProdutoCategoria(produto_id=produto.codigo, categoria_id=categoria.id))

    # Ingredientes
    for ing in data["ingredientes"]:
        nome = ing.get("text")
        if not nome:
            continue
        ingrediente = db.query(Ingrediente).filter_by(nome=nome).first()
        if not ingrediente:
            ingrediente = Ingrediente(
                nome=nome,
                vegano=ing.get("vegan") == "yes",
                vegetariano=ing.get("vegetarian") == "yes"
            )
            db.add(ingrediente)
            db.flush()
        db.add(ProdutoIngrediente(produto_id=produto.codigo, ingrediente_id=ingrediente.id))

    # Nutrientes
    for nome, valor in data["nutrientes"].items():
        if not isinstance(valor, (int, float)):
            continue
        unidade = "g"
        nutriente = db.query(Nutriente).filter_by(nome=nome).first()
        if not nutriente:
            nutriente = Nutriente(nome=nome, unidade=unidade)
            db.add(nutriente)
            db.flush()
        db.add(ProdutoNutriente(produto_id=produto.codigo, nutriente_id=nutriente.id, quantidade_100g=valor))

    # Tags
    for tag_nome in data["tags"]:
        tipo = "additive" if "add" in tag_nome else "allergen"
        tag = db.query(Tag).filter_by(nome=tag_nome, tipo=tipo).first()
        if not tag:
            tag = Tag(nome=tag_nome, tipo=tipo)
            db.add(tag)
            db.flush()
        db.add(ProdutoTag(produto_id=produto.codigo, tag_id=tag.id))

    db.flush()

