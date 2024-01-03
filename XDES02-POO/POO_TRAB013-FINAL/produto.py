import tkinter as tk
from tkinter import messagebox
import os.path
import pickle

#Definimos a classe Produto
class Produto:
  def __init__(self, codigo, desc, valorUni):
    self.codigo = codigo
    self.desc = desc
    self.valorUni = valorUni

#Property e setter dos atributos
  @property
  def codigo(self):
    return self.__codigo
  
  @codigo.setter
  def codigo(self, codigo):
    self.__codigo = codigo
  
  @property
  def desc(self):
    return self.__desc
  
  @desc.setter
  def desc(self, desc):
    self.__desc = desc
  
  @property
  def valorUni(self):
    return self.__valorUni
  
  @valorUni.setter
  def valorUni(self, valorUni):
    self.__valorUni = valorUni

#Definimos o limite para a janela de cadastramento de produtos
class LimiteCadastraProduto(tk.Toplevel):
  def __init__(self, controle,tipo):
    tk.Toplevel.__init__(self)
    self.geometry('250x100')
    self.title("Novo Produto")
    self.controle = controle

    #frames dos atributos
    self.frameCodigo = tk.Frame(self)
    self.frameDesc = tk.Frame(self)
    self.frameValor = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    #Pack para projetar os frames
    self.frameCodigo.pack()
    self.frameDesc.pack()
    self.frameValor.pack()
    self.frameButton.pack()

    #label para podermos rotular com o nome dos atributos / pack
    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelDesc = tk.Label(self.frameDesc,text="Descrição: ")
    self.labelValor = tk.Label(self.frameValor,text="Preco por KG: ")
    self.labelCodigo.pack(side="left")
    self.labelDesc.pack(side="left")  
    self.labelValor.pack(side="left")  

    #input para receber as entradas referente aos atributos
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")
    self.inputDesc = tk.Entry(self.frameDesc, width=20)
    self.inputDesc.pack(side="left")
    self.inputValor = tk.Entry(self.frameValor, width=20)
    self.inputValor.pack(side="left")          

    #Usamos as configurações para botão de cadastrar, clear e concluído. Ambos possuem funções bindadas para ativar comandos
    self.buttonSubmit = tk.Button(self.frameButton ,text="Cadastrar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.enterHandler)
  
    self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", lambda event, t=tipo: controle.fechaHandler(event, t))

  #Função para retornar mensagem quando for chamada
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

#Definimos a janela para consulta de produtos
class LimiteConsultaProduto(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('200x200')
    self.title("Consultar Produtos")
    self.ctrl = controle

    #frames dos atributos
    self.frameCodigo = tk.Frame(self)
    self.frameProdutos = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCodigo.pack()
    self.frameProdutos.pack()
    self.frameButton.pack()

    #label do código
    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelCodigo.pack(side="left")

    #input para armazenar entradas referente ao atributo codigo para posteriormente realizar consulta
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")

    #usamos tk.text para organizar um espaço, o qual conterá as informações referente ao código, podendo devolver infos ou mensagem negativa para ausência de produto
    self.textProduto = tk.Text(self.frameProdutos, height=8,width=20)
    self.textProduto.pack()
    self.textProduto.config(state=tk.DISABLED)

    #Configuramos um botão bindado para a função buscaProduto
    self.buttonSubmit = tk.Button(self.frameButton ,text="Consultar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.buscaProduto)

#Definimos a janela para alterar os produtos
class LimiteAlteraProduto(tk.Toplevel):
  def __init__(self, controle,tipo):
    tk.Toplevel.__init__(self)
    self.geometry('250x100')
    self.title("Novo Produto")
    self.controle = controle

    #frames para os atributos/pack
    self.frameCodigo = tk.Frame(self)
    self.frameDesc = tk.Frame(self)
    self.frameValor = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCodigo.pack()
    self.frameDesc.pack()
    self.frameValor.pack()
    self.frameButton.pack()
    
    #label para rotular os atributos/pack
    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelDesc = tk.Label(self.frameDesc,text="Descrição: ")
    self.labelValor = tk.Label(self.frameValor,text="Preco por KG: ")
    self.labelCodigo.pack(side="left")
    self.labelDesc.pack(side="left")  
    self.labelValor.pack(side="left")  

    #inputs para armazenar as entradas nas variaveis 
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")
    self.inputDesc = tk.Entry(self.frameDesc, width=20)
    self.inputDesc.pack(side="left")
    self.inputValor = tk.Entry(self.frameValor, width=20)
    self.inputValor.pack(side="left")          

    #criamos botões bindados para ativar funções para alterar, limpar e fechar
    self.buttonSubmit = tk.Button(self.frameButton ,text="Alterar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.alteraHandler)

    self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", lambda event, t=tipo: controle.fechaHandler(event, t))

  #função que retorna mensagem quando chamada
  def mostraJanela(self, titulo, msg):
      messagebox.showinfo(titulo, msg)

#Definimos a janela para remover produtos
class LimiteRemoveProduto(tk.Toplevel):
  def __init__(self, controle,tipo):
    tk.Toplevel.__init__(self)
    self.geometry('250x100')
    self.title("Remover Produto")
    self.controle = controle
    
    #frames para atributos/pack
    self.frameCodigo = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCodigo.pack()
    self.frameButton.pack()
    

    #label para rotulos dos atributos
    self.labelCodigo = tk.Label(self.frameCodigo,text="Código para remover: ")
    self.labelCodigo.pack(side="left")

    #inputs para armazenar entradas nas variaveis
    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")
    
    #Configuramos botões que ativam funções para remover produto da lista, limpa e fecha janela.
    self.buttonSubmit = tk.Button(self.frameButton ,text="Remover")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.removeHandler)

    self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", lambda event, t=tipo: controle.fechaHandler(event, t))

  #Função para mostrar mensagem quando chamada
  def mostraJanela(self, titulo, msg):
      messagebox.showinfo(titulo, msg)

#Controller do produto e configuração de pickle para armazenar em arquivo
class CtrlProduto():       
  def __init__(self):
    if not os.path.isfile("produto.pickle"):
      self.listaProdutos =  []
    else:
      with open("produto.pickle", "rb") as f:
        self.listaProdutos = pickle.load(f)
  
  def salvaProdutos(self):
    if len(self.listaProdutos) != 0:
      with open("produto.pickle","wb") as f:
          pickle.dump(self.listaProdutos, f)

  def cadastraProduto(self):
    self.limiteCad = LimiteCadastraProduto(self, 'cadastra')
  
  def consultaProduto(self):
    self.limiteCons = LimiteConsultaProduto(self)

  def alteraProduto(self):
    self.limiteAlt = LimiteAlteraProduto(self, 'altera')

  def removeProduto(self):
    self.limiteRem = LimiteRemoveProduto(self, 'remove')

  #configuração enterHandler, usa get(), armazena na variavel, cria objeto e appenda na lista mostrando mensagem
  def enterHandler(self, event):
    codigo = self.limiteCad.inputCodigo.get()
    desc = self.limiteCad.inputDesc.get()
    valor = self.limiteCad.inputValor.get()
    produto = Produto(codigo, desc, valor)
    self.listaProdutos.append(produto)
    self.limiteCad.mostraJanela('Sucesso!', 'Produto cadastrado com sucesso')
    self.clearHandler(event)

  #configuração clearHandler, deleta os caracteres presentes nos inputs
  def clearHandler(self, event):
    self.limiteCad.inputCodigo.delete(0, len(self.limiteCad.inputCodigo.get()))
    self.limiteCad.inputDesc.delete(0, len(self.limiteCad.inputDesc.get()))
    self.limiteCad.inputValor.delete(0, len(self.limiteCad.inputValor.get()))

  #destroy() para fechar janela 
  def fechaHandler(self, event, tipo):
    if tipo == 'cadastra':
        self.limiteCad.destroy()
    elif tipo == 'altera':
        self.limiteAlt.destroy()
    elif tipo == 'remove':
        self.limiteRem.destroy()
  
  #Função que busca produtos referente ao código de entrada
  def buscaProduto(self, event):
    codigo = self.limiteCons.inputCodigo.get()
    self.limiteCons.textProduto.config(state='normal')
    self.limiteCons.textProduto.delete("1.0", tk.END)
    prodRet = None
    for prod in self.listaProdutos:
      if prod.codigo == codigo:
          prodRet = prod
    
    if prodRet == None:
      self.limiteCons.inputCodigo.delete(0, len(self.limiteCons.inputCodigo.get()))
      self.limiteCons.textProduto.insert(1.0, 'Produto não encontrado!')
    else:
      self.limiteCons.inputCodigo.delete(0, len(self.limiteCons.inputCodigo.get()))
      self.limiteCons.textProduto.insert(1.0, 'Código: {}\nDescrição: {}\nPreço por Kg: R${}'.format(prodRet.codigo, prodRet.desc, prodRet.valorUni))
    self.limiteCons.textProduto.config(state = 'disable')

  #Função para get da lista de codigos dos produtos contidos na listaProdutos, e posteriormente usada para cadastrarCupom
  def getListaCodigosProdutos(self):
    codsProdutos = []
    for prod in self.listaProdutos:
      codsProdutos.append(prod.codigo)
      
    return codsProdutos
  
  #Método getProd
  def getProd(self, codigo):
    prodRet = None
    for prod in self.listaProdutos:
      if prod.codigo == codigo:
          prodRet = prod
    return prodRet
  
  #Método para alterar os atributos referente ao código
  def alteraHandler(self, event):
    codigo = self.limiteAlt.inputCodigo.get()
    prodRet = None
    for prod in self.listaProdutos:
      if prod.codigo == codigo:
          prodRet = prod
  
    if prodRet == None:
      self.limiteAlt.inputCodigo.delete(0, len(self.limiteAlt.inputCodigo.get()))

    else:
      self.limiteAlt.inputCodigo.delete(0, len(self.limiteAlt.inputCodigo.get()))
      novo_preco = self.limiteAlt.inputValor.get()
      nova_carne = self.limiteAlt.inputDesc.get()

      prodRet.desc = nova_carne
      prodRet.valorUni = novo_preco

      
      self.limiteAlt.mostraJanela('Sucesso!', 'Produto alterado com sucesso')
      self.clearHandler(event)
  
  #Método para remover ovjeto referente ao código
  def removeHandler(self, event):
    codigo = self.limiteRem.inputCodigo.get()
    prodRet = None
    for prod in self.listaProdutos:
        if prod.codigo == codigo:
            prodRet = prod
            break  

    if prodRet is not None:
        self.listaProdutos.remove(prodRet)
        self.limiteRem.mostraJanela('Sucesso!', 'Produto removido com sucesso')
    else:
        self.limiteRem.mostraJanela('Erro!', 'Produto não encontrado')

    self.clearHandler(event)

  
  