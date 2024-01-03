import tkinter as tk
import artista
import album
import musica
import playlist

class LimitePrincipal:
  def __init__(self, raiz, controle):
    self.raiz = raiz
    self.controle = controle
    self.raiz.geometry('300x200')
    self.raiz.title('U n i f e i - P l a y')
    self.raiz.configure(bg='yellowgreen')
    self.raiz.config(cursor="hand2")
    self.raiz.resizable(width=True, height=True)


    self.menuBar = tk.Menu(self.raiz)
    self.menuArtista = tk.Menu(self.menuBar)
    self.menuMusica = tk.Menu(self.menuBar)
    self.menuAlbum = tk.Menu(self.menuBar)
    self.menuPlaylist = tk.Menu(self.menuBar)
    self.menuSair = tk.Menu(self.menuBar)
    

    self.menuArtista.add_command(label = 'Cadastrar', command = self.controle.createArtista)
    self.menuArtista.add_command(label = 'Consultar', command = self.controle.findArtista)
    self.menuBar.add_cascade(label = 'Artista', menu = self.menuArtista)

    self.menuAlbum.add_command(label = 'Cadastrar', command = self.controle.createAlbum)
    self.menuAlbum.add_command(label = 'Consultar', command = self.controle.findAlbum)
    self.menuBar.add_cascade(label = 'Álbum', menu = self.menuAlbum)

    self.menuMusica.add_command(label = 'Cadastrar', command = self.controle.createMusica)
    self.menuMusica.add_command(label = 'Consultar', command = self.controle.findMusica)
    self.menuBar.add_cascade(label = 'Música', menu = self.menuMusica)

    self.menuPlaylist.add_command(label = 'Cadastrar', command = self.controle.createPlaylist)
    self.menuPlaylist.add_command(label = 'Consultar', command = self.controle.findPlaylist)
    self.menuBar.add_cascade(label = 'Playlist', menu = self.menuPlaylist)

    self.menuSair.add_command(label = 'Salvar', command = self.controle.saveDados)
    self.menuSair.add_command(label = 'Não Salvar', command = lambda: self.raiz.destroy())
    self.menuBar.add_cascade(label = 'Sair', menu = self.menuSair)

    self.raiz.config(menu=self.menuBar)

class ControlePrincipal:
  def __init__(self):
    self.raiz = tk.Tk()
    self.limite = LimitePrincipal(self.raiz, self)
    self.artistaController = artista.ArtistaController()
    self.musicaController = musica.MusicaController(self)
    self.albumController = album.AlbumController(self)
    self.playlistController = playlist.PlaylistController(self)

    self.raiz.mainloop()

  def createArtista(self):
    self.artistaController.cadastraArtista()

  def findArtista(self):
    self.artistaController.findArtista()

  def createMusica(self):
    self.musicaController.cadastraMusica()

  def findMusica(self):
    self.musicaController.findMusica()

  def createAlbum(self):
    self.albumController.cadastraAlbum()

  def findAlbum(self):
    self.albumController.findAlbum()

  def createPlaylist(self):
    self.playlistController.cadastraPlaylist()
    self.playlistController.atualizaListBox()

  def findPlaylist(self):
    self.playlistController.findPlaylist()

  def saveDados(self):
    self.artistaController.saveArtista()
    self.albumController.saveAlbum()
    self.musicaController.saveMusica()
    self.playlistController.savePlaylist()
    self.raiz.destroy()

if __name__ == '__main__':
  App = ControlePrincipal()