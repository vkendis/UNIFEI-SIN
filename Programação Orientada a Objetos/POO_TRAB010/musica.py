import tkinter as tk
from tkinter import messagebox
import pickle
import os

class Musica:
  def __init__(self, titulo, nroFaixa, artista, album):
    self.titulo = titulo
    self.nroFaixa = nroFaixa
    self.artista = artista
    self.album = album

  def getTitulo(self):
    return self.titulo
  
  def getNroFaixa(self):
    return self.nroFaixa
  
  def getArtista(self):
    return self.artista
  
  def getAlbum(self):
    return self.album
  
class LimiteInsereMusica(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x125')
    self.title('Inserir Musica')
    self.controle = controle

    self.frameTitulo = tk.Frame(self)
    self.frameFaixa = tk.Frame(self)
    self.frameArtista = tk.Frame(self)
    self.frameAlbum = tk.Frame(self)
    self.frameButtom = tk.Frame(self)
    self.frameTitulo.pack()
    self.frameFaixa.pack()
    self.frameArtista.pack()
    self.frameAlbum.pack()
    self.frameButtom.pack()

    self.labelInsereTitulo = tk.Label(self.frameTitulo, text = 'Título da Música: ')
    self.labelInsereTitulo.pack(side = 'left')
    self.entraTitulo = tk.Entry(self.frameTitulo, width = 20)
    self.entraTitulo.pack(side = 'left')

    self.labelInsereFaixa = tk.Label(self.frameFaixa, text = 'Faixa da Música: ')
    self.labelInsereFaixa.pack(side = 'left')
    self.entraFaixa = tk.Entry(self.frameFaixa, width = 20)
    self.entraFaixa.pack(side = 'left')

    self.labelInsereArtista = tk.Label(self.frameArtista, text = 'Artista da Música: ')
    self.labelInsereArtista.pack(side = 'left')
    self.entraArtista = tk.Entry(self.frameArtista, width = 20)
    self.entraArtista.pack(side = 'left')

    self.labelInsereAlbum = tk.Label(self.frameAlbum, text = 'Album da Música: ')
    self.labelInsereAlbum.pack(side = 'left')
    self.entraAlbum = tk.Entry(self.frameAlbum, width = 20)
    self.entraAlbum.pack(side = 'left')

    self.buttomCadastrar = tk.Button(self.frameButtom, text = 'Cadastrar')
    self.buttomCadastrar.pack(side = 'left')
    self.buttomCadastrar.bind('<Button>', controle.cadastrarMusicaHandler)

    self.buttomConcluido = tk.Button(self.frameButtom, text = 'Sair')
    self.buttomConcluido.pack(side = 'left')
    self.buttomConcluido.bind('<Button>', controle.concluidoInsereHandler)
  
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class LimiteConsultaMusica(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x50')
    self.title('Consultar Música')
    self.controle = controle

    self.frameMusica = tk.Frame(self)
    self.frameButtom = tk.Frame(self)
    self.frameMusica.pack()
    self.frameButtom.pack()

    self.labelTitulo = tk.Label(self.frameMusica, text = 'Título da Música: ')
    self.entraTitulo = tk.Entry(self.frameMusica, width = 20)
    self.labelTitulo.pack(side = 'left')
    self.entraTitulo.pack(side = 'left')

    self.buttomConsultar = tk.Button(self.frameButtom, text = 'Consultar')
    self.buttomConsultar.pack()
    self.buttomConsultar.bind('<Button>', controle.consultarMusicaHandler)

class LimiteMostraMusica:
  def __init__(self, strr, tipo):
    if tipo:
      messagebox.showinfo('Música encontrada', strr)
    else:
      messagebox.showinfo('Aviso', strr)

class MusicaController:
  def __init__(self, controlePrincipal):
    if not os.path.isfile('./musica.pickle'):
      self.listaMusicas = []
    else:
      with open('./musica.pickle', 'rb') as f:
        self.listaMusicas = pickle.load(f)
    
    self.controlePrincipal = controlePrincipal
    self.artistaController = controlePrincipal.artistaController

      
  def getMusicas(self):
    return self.listaMusicas

  def cadastraMusica(self):
    self.LimiteCadastraMusica = LimiteInsereMusica(self)
  
  def findMusica(self):
    self.LimiteBuscaMusica = LimiteConsultaMusica(self)

  def cadastrarMusicaHandler(self, event):
    titulo = self.LimiteCadastraMusica.entraTitulo.get()
    faixa = self.LimiteCadastraMusica.entraFaixa.get()
    nomeArtista = self.LimiteCadastraMusica.entraArtista.get()
    nomeAlbum = self.LimiteCadastraMusica.entraAlbum.get()
    
    for art in self.artistaController.getArtistas():
      if self.isSameArtista(nomeArtista, art.getNome()):
        artista = art
        break
      if self.isSameArtista(art.getNome(), self.artistaController.getArtistas()[-1].getNome()):
        self.LimiteCadastraMusica.mostraJanela('Aviso', 'Artista não encontrado')
        return False

    for alb in artista.getAlbuns():
      if self.isSameAlbum(nomeAlbum, alb.getTitulo()):
        album = alb
        break
      if self.isSameAlbum(alb.getTitulo(), artista.getAlbuns()[-1].getTitulo()):
        self.LimiteCadastraMusica.mostraJanela('Aviso', 'Álbum não encontrado')
        return False
    
    musica = Musica(titulo, faixa, artista, album)
    self.listaMusicas.append(musica)
    artista.addMusica(musica)
    album.addMusica(musica)
    self.LimiteCadastraMusica.mostraJanela('Sucesso', 'Música cadastrada com sucesso')
    self.limpaTituloInsere(event)
    self.limpaFaixaInsere(event)
      
  def isSameArtista(self, artista1, artista2):
    return artista1.strip().lower() == artista2.strip().lower()

  def isSameAlbum(self, album1, album2):
    return album1.strip().lower() == album2.strip().lower()

  def isSameMusic(self, music1, music2):
    return music1.strip().lower() == music2.strip().lower()

  def consultarMusicaHandler(self, event):
    musica = self.LimiteBuscaMusica.entraTitulo.get()
    strr = ''

    for musc in self.getMusicas():
      if self.isSameMusic(musica, musc.getTitulo()):
        strr += f"Música: {musc.getTitulo()}\n"
        strr += f"Faixa: {musc.getNroFaixa()}\n"
        strr += f"Artista: {musc.getArtista().getNome()}\n"
        strr += f"Álbum: {musc.getAlbum().getTitulo()}"
        LimiteMostraMusica(strr, True)
        self.limpaTituloConsulta(event)
        return

    LimiteMostraMusica('Musica não encontrada', False)
    self.limpaTituloConsulta(event)

  # Reset form
  def limpaTituloInsere(self, event):
    self.LimiteCadastraMusica.entraTitulo.delete(0, len(self.LimiteCadastraMusica.entraTitulo.get()))

  def limpaFaixaInsere(self, event):
    self.LimiteCadastraMusica.entraFaixa.delete(0, len(self.LimiteCadastraMusica.entraFaixa.get()))
  
  def limpaTituloConsulta(self, event):
    self.LimiteBuscaMusica.entraTitulo.delete(0, len(self.LimiteBuscaMusica.entraTitulo.get()))

  # Salvar dados
  def saveMusica(self):
    if len(self.listaMusicas) != 0:
      with open("./musica.pickle", "wb") as f:
        pickle.dump(self.listaMusicas, f)
  
  def concluidoInsereHandler(self,event):
    self.LimiteCadastraMusica.destroy()
  
  def concluidoConsultaHandler(self,event):
    self.LimiteBuscaMusica.destroy()