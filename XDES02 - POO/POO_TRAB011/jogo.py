import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Jogo:
  def __init__(self, codigo, titulo, console, genero, preco):
    self.codigo = codigo
    self.titulo = titulo
    self.console = console
    self.genero = genero
    self.preco = preco
    self.__avaliacoes = []

  @property
  def codigo(self):
    return self.__codigo
  
  @codigo.setter
  def codigo(self, codigo):
    self.__codigo = codigo
  
  @property
  def titulo(self):
    return self.__titulo
  
  @titulo.setter
  def titulo(self, titulo):
    self.__titulo = titulo
  
  @property
  def console(self):
    return self.__console
  
  @console.setter
  def console(self, console):
    self.consoles = ["XBox", "PlayStation", "Switch", "PC"]

    if not console in self.consoles:
      raise ValueError("Console inválido: {}".format(console))
    else:
      self.__console = console
  
  @property
  def genero(self):
    return self.__genero
  
  @genero.setter
  def genero(self, genero):
    self.generos = ["Ação", "Aventura", "Estratégia", "RPG", "Esporte", "Simulação"]
    
    if not genero in self.generos:
      raise ValueError("Gênero inválido: {}".format(genero))
    else:
      self.__genero = genero
  
  @property
  def preco(self):
    return self.__preco
  
  @preco.setter
  def preco(self, preco):
    if preco < 0 or preco > 500:
      raise ValueError("Preço incompatível: R${}".format(preco))
    else:
      self.__preco = preco
  
  @property
  def avaliacoes(self):
    return self.__avaliacoes
  
  def infosJogo(self):
    return "Título: " + str(self.titulo)\
    + "\nCodigo: " + str(self.codigo)\
    + "\nConsole: " + str(self.console)\
    + "\nGênero: " + str(self.genero)\
    + "\nPreço: R$" + str(self.preco)\
    + "\nAvaliação: " + str(sum(self.avaliacoes)/len(self.avaliacoes))

class LimiteCadastraJogo(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x250')
    self.title("Novo Jogo")
    self.controle = controle

    self.frameCodigo = tk.Frame(self)
    self.frameTitulo = tk.Frame(self)
    self.frameConsole = tk.Frame(self)
    self.frameGenero = tk.Frame(self)
    self.framePreco = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCodigo.pack()
    self.frameTitulo.pack()
    self.frameConsole.pack()
    self.frameGenero.pack()
    self.framePreco.pack()
    self.frameButton.pack()

    # Botão e Entry para Código
    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelCodigo.pack(side="left")
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")

    # Botão e Entry para Título
    self.labelTitulo = tk.Label(self.frameTitulo,text="Título: ")
    self.labelTitulo.pack(side="left")
    self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
    self.inputTitulo.pack(side="left")

    # Botão e Entry para Console
    self.labelConsole = tk.Label(self.frameConsole,text="Console: ")
    self.labelConsole.pack(side="left")
    self.inputConsole = tk.Entry(self.frameConsole, width=20)
    self.inputConsole.pack(side="left")

    # Botão e Entry para Gênero
    self.labelGenero = tk.Label(self.frameGenero,text="Gênero: ")
    self.labelGenero.pack(side="left")
    self.inputGenero = tk.Entry(self.frameGenero, width=20)
    self.inputGenero.pack(side="left")

    # Botão e Entry para Preço
    self.labelPreco = tk.Label(self.framePreco,text="Preço: ")
    self.labelPreco.pack(side="left")
    self.inputPreco = tk.Entry(self.framePreco, width=20)
    self.inputPreco.pack(side="left")      
  
    self.buttonSubmit = tk.Button(self.frameButton ,text="Cadastrar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.enterHandler)
  
    self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", controle.fechaHandler)

  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)
    
#Classe avaliação
class LimiteAvaliaJogo(tk.Toplevel):
  def __init__(self, controle, estrelas):
    tk.Toplevel.__init__(self)
    self.geometry('250x100')
    self.title("Avaliar Jogo")
    self.ctrl = controle

    self.frameCodigo = tk.Frame(self)
    self.frameAvaliacao = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCodigo.pack()
    self.frameAvaliacao.pack()
    self.frameButton.pack()

    self.labelCodigo = tk.Label(self.frameCodigo,text="Código do Jogo: ")
    self.labelCodigo.pack(side="left")
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")

    self.labelAvaliacao = tk.Label(self.frameAvaliacao,text="Avaliação: ")
    self.labelAvaliacao.pack(side="left")
    self.escolhaAvaliacao = tk.StringVar()
    self.comboboxAvaliacao = ttk.Combobox(self.frameAvaliacao, width = 15 ,values=estrelas, textvariable = self.escolhaAvaliacao)
    self.comboboxAvaliacao.pack(side="left")

    self.buttonSubmit = tk.Button(self.frameButton ,text="Avaliar!")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.salvaAvaliacao)
  
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class LimiteConsultaJogo(tk.Toplevel):
  def __init__(self, controle, estrelas):
    tk.Toplevel.__init__(self)
    self.geometry('400x400')
    self.title("Consultar Cupom Fiscal")
    self.ctrl = controle

    self.frameAvaliacao = tk.Frame(self)
    self.frameJogos = tk.Frame(self)
    self.frameAvaliacao.pack()
    self.frameJogos.pack()

    self.labelAvaliacao = tk.Label(self.frameAvaliacao,text="Avaliação: ")
    self.labelAvaliacao.pack(side="left")
    self.escolhaAvaliacao = tk.StringVar()
    self.comboboxAvaliacao = ttk.Combobox(self.frameAvaliacao, width = 15 ,values=estrelas, textvariable = self.escolhaAvaliacao)
    self.comboboxAvaliacao.pack(side="left")
    self.comboboxAvaliacao.bind("<<ComboboxSelected>>", self.ctrl.exibeJogos)

    self.textJogos = tk.Text(self.frameJogos, height=20,width=40)
    self.textJogos.pack()
    self.textJogos.config(state=tk.DISABLED) 
    
class CtrlJogo():       
  def __init__(self):
    self.estrelas = ["⭐", "⭐⭐", "⭐⭐⭐", "⭐⭐⭐⭐", "⭐⭐⭐⭐⭐"]
    if not os.path.isfile("jogos.pickle"):
      self.listaJogos =  []
    else:
      with open("jogos.pickle", "rb") as f:
        self.listaJogos= pickle.load(f)
  
  def salvaJogos(self):
    if len(self.listaJogos) != 0:
      with open("jogos.pickle","wb") as f:
        pickle.dump(self.listaJogos, f)

  def cadastraJogo(self):
    self.limiteCad = LimiteCadastraJogo(self)
  
  def avaliaJogo(self):
    self.limiteAva = LimiteAvaliaJogo(self, self.estrelas)
  
  def consultaJogo(self):
    self.limiteCons = LimiteConsultaJogo(self, self.estrelas)
  
  def enterHandler(self, event):
    codigo = self.limiteCad.inputCodigo.get()
    titulo = self.limiteCad.inputTitulo.get()
    console = self.limiteCad.inputConsole.get()
    genero = self.limiteCad.inputGenero.get()
    preco = int(self.limiteCad.inputPreco.get())
    jogo = Jogo(codigo, titulo, console, genero, preco)
    self.listaJogos.append(jogo)
    self.limiteCad.mostraJanela('Sucesso!', 'Jogo cadastrado com sucesso!')
    self.clearHandler(event)
  
  def clearHandler(self, event):
    self.limiteCad.inputCodigo.delete(0, len(self.limiteCad.inputCodigo.get()))
    self.limiteCad.inputTitulo.delete(0, len(self.limiteCad.inputTitulo.get()))
    self.limiteCad.inputConsole.delete(0, len(self.limiteCad.inputConsole.get()))
    self.limiteCad.inputGenero.delete(0, len(self.limiteCad.inputGenero.get()))
    self.limiteCad.inputPreco.delete(0, len(self.limiteCad.inputPreco.get()))

  def fechaHandler(self, event):
    self.limiteCad.destroy()
  
  def salvaAvaliacao(self, event):
    codigo = self.limiteAva.inputCodigo.get()
    jogo = self.getJogo(codigo)

    if jogo == None:
      self.limiteAva.mostraJanela('Erro!!!', 'Jogo não encontrado!')
    else:
      num = 0
      avaliacao = self.limiteAva.comboboxAvaliacao.get()

      num = self.transEestrela(avaliacao)
      
      jogo.avaliacoes.append(num)
      self.limiteAva.mostraJanela('Sucesso!', 'Avaliação do jogo {} cadastrada com sucesso!'.format(jogo.titulo))
  
  def getJogo(self, codigo):
    jogoRet = None
    for jogo in self.listaJogos:
      if jogo.codigo == codigo:
          jogoRet = jogo
    return jogoRet

  def transEestrela(self, estrelas):
    if estrelas == "⭐":
      num = 1
    elif estrelas == "⭐⭐":
      num = 2
    elif estrelas == "⭐⭐⭐":
      num = 3
    elif estrelas == "⭐⭐⭐⭐":
      num = 4
    else:
      num = 5
    
    return num;
  
  def exibeJogos(self, event):
    avaliacao = self.limiteCons.comboboxAvaliacao.get()
    num = self.transEestrela(avaliacao)
    media = 0
    jogos = None
    self.limiteCons.textJogos.config(state='normal')
    self.limiteCons.textJogos.delete("1.0", tk.END)
    for jogo in self.listaJogos:
      if(len(jogo.avaliacoes) != 0):
        media = sum(jogo.avaliacoes)/len(jogo.avaliacoes)
        if(media > num-1 and media <= num):
          jogos = jogo.infosJogo() + '\n\n'
          self.limiteCons.textJogos.insert(1.0, jogos)
    
    if jogos == None:
      self.limiteCons.textJogos.insert(1.0, "Não há jogos com {} estrelas".format(num))

    self.limiteCons.textJogos.config(state = 'disable')
        