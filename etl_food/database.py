# database.py
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model import Base

DATABASE_URL = "postgresql://postgres:123@localhost:5433/postgres"

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(bind=engine, autoflush=False, autocommit=False)

def get_db_session():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()

def create_database_tables():
    """Cria todas as tabelas no banco de dados se não existirem."""
    Base.metadata.create_all(bind=engine)
    print("Tabelas verificadas/criadas com sucesso.")
