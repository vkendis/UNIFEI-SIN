import tkinter as tk
from tkinter import messagebox
import pickle
import os

class Artista:
  def __init__(self, nome):
    self.nome = nome
    self.albuns = []
    self.musicas = []
  
  def getNome(self):
    return self.nome
  
  def getAlbuns(self):
    return self.albuns
  
  def getMusicas(self):
    return self.musicas
  
  def addMusica(self, musica):
    self.musicas.append(musica)
  
  def addAlbum(self, album):
    self.albuns.append(album)

class LimiteInsereArtista(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x50')
    self.title('Inserir Artista')
    self.controle = controle

    self.frameNome = tk.Frame(self)
    self.frameButtom = tk.Frame(self)
    self.frameNome.pack()
    self.frameButtom.pack()

    self.labelInsereNome = tk.Label(self.frameNome, text = 'Nome do artista: ')
    self.labelInsereNome.pack(side = 'left')
    self.entraNome = tk.Entry(self.frameNome, width = 20)
    self.entraNome.pack(side = 'left')

    self.buttomCadastrar = tk.Button(self.frameButtom, text = 'Cadastrar')
    self.buttomCadastrar.pack(side = 'left')
    self.buttomCadastrar.bind('<Button>', controle.cadastrarArtistaHandler)

    self.buttomConcluido = tk.Button(self.frameButtom, text = 'Sair')
    self.buttomConcluido.pack(side = 'left')
    self.buttomConcluido.bind('<Button>', controle.concluidoInsereHandler)
  
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class LimiteConsultaArtista(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x50')
    self.title('Consultar Artista')
    self.controle = controle

    self.frameArtista = tk.Frame(self)
    self.frameButtom = tk.Frame(self)
    self.frameArtista.pack()
    self.frameButtom.pack()

    self.labelNome = tk.Label(self.frameArtista, text = 'Nome do Artista: ')
    self.entraNome = tk.Entry(self.frameArtista, width = 20)
    self.labelNome.pack(side = 'left')
    self.entraNome.pack(side = 'left')

    self.buttomConsultar = tk.Button(self.frameButtom, text = 'Consultar')
    self.buttomConsultar.pack()
    self.buttomConsultar.bind('<Button>', controle.consultarArtistaHandler)

class LimiteMostraArtista:
  def __init__(self, strr, tipo):
    if tipo:
      messagebox.showinfo('Lista de Álbuns', strr)
    else:
      messagebox.showinfo('Aviso', strr)

class ArtistaController:
  def __init__(self):
    if not os.path.isfile('./artista.pickle'):
      self.listaArtistas = []
    else:
      with open('./artista.pickle', 'rb') as f:
        self.listaArtistas = pickle.load(f)

  def getArtistas(self):
    return self.listaArtistas

  def cadastraArtista(self):
    self.LimiteCadastraArtista = LimiteInsereArtista(self)
  
  def findArtista(self):
    self.LimiteBuscaArtista = LimiteConsultaArtista(self)

  def cadastrarArtistaHandler(self, event):
    nome = self.LimiteCadastraArtista.entraNome.get()
    self.listaArtistas.append(Artista(nome))
    self.LimiteCadastraArtista.mostraJanela('Sucesso', 'Artista cadastrado com sucesso')
    self.limpaNomeInsere(event)
  
  def consultarArtistaHandler(self, event):
    nome = self.LimiteBuscaArtista.entraNome.get()
    strr = f"{nome}\n\n"
    for artista in self.getArtistas():
      if self.isSameArtista(nome, artista.getNome()):
        for albuns in artista.getAlbuns():
          strr += f"{albuns.getTitulo()}\n\n"
          for musicas in albuns.getMusicas():
            strr += f"{musicas.getNroFaixa()} {musicas.getTitulo()}\n"
          strr += "________________________________\n\n"
        LimiteMostraArtista(strr, True)
        self.limpaNomeConsulta(event)
        return
    LimiteMostraArtista('Artista não encontrado', False)
    self.limpaNomeConsulta(event)
  
  def isSameArtista(self, artista1, artista2):
    return artista1.strip().lower() == artista2.strip().lower()

  # Reset form
  def limpaNomeInsere(self, event):
    self.LimiteCadastraArtista.entraNome.delete(0, len(self.LimiteCadastraArtista.entraNome.get()))
  
  def limpaNomeConsulta(self):
    self.LimiteBuscaArtista.entraNome.delete(0, len(self.LimiteBuscaArtista.entraNome.get()))

  # Salvar dados
  def saveArtista(self):
    if len(self.listaArtistas) != 0:
      with open("./artista.pickle", "wb") as f:
        pickle.dump(self.listaArtistas, f)
  
  def concluidoInsereHandler(self,event):
    self.LimiteCadastraArtista.destroy()
  
  def concluidoConsultaHandler(self,event):
    self.LimiteBuscaArtista.destroy()