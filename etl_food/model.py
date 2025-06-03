from sqlalchemy import (
    create_engine, Column, String, Integer, Enum as SQLAlchemyEnum,
    ForeignKey, DECIMAL, Boolean, UniqueConstraint
)
from sqlalchemy.orm import relationship, declarative_base
import enum

# Enums personalizados
class TipoNutriEcoScoreDB(enum.Enum):
    A = 'A'
    B = 'B'
    C = 'C'
    D = 'D'
    E = 'E'

class TipoNovaScoreDB(enum.Enum):
    _1 = '1'
    _2 = '2'
    _3 = '3'
    _4 = '4'

class TipoTagDB(enum.Enum):
    allergen = 'allergen'
    additive = 'additive'

Base = declarative_base()

# Tabela Produto
class Produto(Base):
    __tablename__ = 'produto'
    codigo = Column(String(255), primary_key=True)
    nome = Column(String(100), nullable=False)
    nutriscore = Column(SQLAlchemyEnum(TipoNutriEcoScoreDB, name='tipo_nutri_eco_score', create_type=False))
    ecoscore = Column(SQLAlchemyEnum(TipoNutriEcoScoreDB, name='tipo_nutri_eco_score', create_type=False))
    novascore = Column(SQLAlchemyEnum(TipoNovaScoreDB, name='tipo_nova_score', create_type=False))

    produto_marcas = relationship("ProdutoMarca", back_populates="produto", cascade="all, delete-orphan")
    produto_nutrientes = relationship("ProdutoNutriente", back_populates="produto", cascade="all, delete-orphan")
    produto_ingredientes = relationship("ProdutoIngrediente", back_populates="produto", cascade="all, delete-orphan")
    produto_tags = relationship("ProdutoTag", back_populates="produto", cascade="all, delete-orphan")
    produto_categorias = relationship("ProdutoCategoria", back_populates="produto", cascade="all, delete-orphan")

# Tabela Marca
class Marca(Base):
    __tablename__ = 'marca'
    id = Column(Integer, primary_key=True, autoincrement=True)
    nome = Column(String(100), nullable=False, unique=True)

    produto_marcas = relationship("ProdutoMarca", back_populates="marca")

# Tabela Nutriente
class Nutriente(Base):
    __tablename__ = 'nutriente'
    id = Column(Integer, primary_key=True, autoincrement=True)
    nome = Column(String(100), nullable=False, unique=True)
    unidade = Column(String(10), nullable=False)

    produto_nutrientes = relationship("ProdutoNutriente", back_populates="nutriente")

# Tabela Ingrediente
class Ingrediente(Base):
    __tablename__ = 'ingrediente'
    id = Column(Integer, primary_key=True, autoincrement=True)
    nome = Column(String(100), nullable=False, unique=True)
    vegano = Column(Boolean)
    vegetariano = Column(Boolean)
    
    produto_ingredientes = relationship("ProdutoIngrediente", back_populates="ingrediente")

# Tabela Tag
class Tag(Base):
    __tablename__ = 'tag'
    id = Column(Integer, primary_key=True, autoincrement=True)
    nome = Column(String(100), nullable=False)
    tipo = Column(SQLAlchemyEnum(TipoTagDB, name='tipo_tag', create_type=False), nullable=False)
    __table_args__ = (UniqueConstraint('nome', 'tipo', name='uq_tag_nome_tipo'),)

    produto_tags = relationship("ProdutoTag", back_populates="tag")

# Tabela Categoria
class Categoria(Base):
    __tablename__ = 'categoria'
    id = Column(Integer, primary_key=True, autoincrement=True)
    nome = Column(String(100), nullable=False, unique=True)

    produto_categorias = relationship("ProdutoCategoria", back_populates="categoria")

# Associações

class ProdutoMarca(Base):
    __tablename__ = 'produto_marca'
    id = Column(Integer, primary_key=True, autoincrement=True)
    produto_id = Column(String(255), ForeignKey('produto.codigo', ondelete="CASCADE"), nullable=False)
    marca_id = Column(Integer, ForeignKey('marca.id', ondelete="RESTRICT"), nullable=False)
    
    produto = relationship("Produto", back_populates="produto_marcas")
    marca = relationship("Marca", back_populates="produto_marcas")
    __table_args__ = (UniqueConstraint('produto_id', 'marca_id', name='uq_produto_marca'),)

class ProdutoNutriente(Base):
    __tablename__ = 'produto_nutriente'
    id = Column(Integer, primary_key=True, autoincrement=True)
    produto_id = Column(String(255), ForeignKey('produto.codigo', ondelete="CASCADE"), nullable=False)
    nutriente_id = Column(Integer, ForeignKey('nutriente.id', ondelete="RESTRICT"), nullable=False)
    quantidade_100g = Column(DECIMAL(6,2))

    produto = relationship("Produto", back_populates="produto_nutrientes")
    nutriente = relationship("Nutriente", back_populates="produto_nutrientes")
    __table_args__ = (UniqueConstraint('produto_id', 'nutriente_id', name='uq_produto_nutriente'),)

class ProdutoIngrediente(Base):
    __tablename__ = 'produto_ingrediente'
    id = Column(Integer, primary_key=True, autoincrement=True)
    produto_id = Column(String(255), ForeignKey('produto.codigo', ondelete="CASCADE"), nullable=False)
    ingrediente_id = Column(Integer, ForeignKey('ingrediente.id', ondelete="RESTRICT"), nullable=False)
    quantidade_estimada = Column(DECIMAL(5,2))

    produto = relationship("Produto", back_populates="produto_ingredientes")
    ingrediente = relationship("Ingrediente", back_populates="produto_ingredientes")
    __table_args__ = (UniqueConstraint('produto_id', 'ingrediente_id', name='uq_produto_ingrediente'),)

class ProdutoTag(Base):
    __tablename__ = 'produto_tag'
    id = Column(Integer, primary_key=True, autoincrement=True)
    produto_id = Column(String(255), ForeignKey('produto.codigo', ondelete="CASCADE"), nullable=False)
    tag_id = Column(Integer, ForeignKey('tag.id', ondelete="RESTRICT"), nullable=False)

    produto = relationship("Produto", back_populates="produto_tags")
    tag = relationship("Tag", back_populates="produto_tags")
    __table_args__ = (UniqueConstraint('produto_id', 'tag_id', name='uq_produto_tag'),)

class ProdutoCategoria(Base):
    __tablename__ = 'produto_categoria'
    id = Column(Integer, primary_key=True, autoincrement=True)
    produto_id = Column(String(255), ForeignKey('produto.codigo', ondelete="CASCADE"), nullable=False)
    categoria_id = Column(Integer, ForeignKey('categoria.id', ondelete="RESTRICT"), nullable=False)
    
    produto = relationship("Produto", back_populates="produto_categorias")
    categoria = relationship("Categoria", back_populates="produto_categorias")
    __table_args__ = (UniqueConstraint('produto_id', 'categoria_id', name='uq_produto_categoria'),)
