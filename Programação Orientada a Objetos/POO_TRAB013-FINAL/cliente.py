import tkinter as tk
from tkinter import messagebox
import os.path
import pickle

#Definimos a classe cliente
class Cliente:
  def __init__(self, nome, email, cpf):
    self.nome = nome
    self.email = email
    self.cpf = cpf

  @property
  def nome(self):
    return self.__nome
  
  @nome.setter
  def nome(self, nome):
    self.__nome = nome
  
  @property
  def email(self):
    return self.__email
  
  @email.setter
  def email(self, email):
    self.__email = email
  
  @property
  def cpf(self):
    return self.__cpf
  
  @cpf.setter
  def cpf(self, cpf):
    self.__cpf = cpf

#Definimos a janela para cadastrar cliente
class LimiteCadastraCliente(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('250x100')
    self.title("Novo Cliente")
    self.controle = controle

    #frame para atributos/pack
    self.frameNome = tk.Frame(self)
    self.frameEmail = tk.Frame(self)
    self.frameCpf = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameNome.pack()
    self.frameEmail.pack()
    self.frameCpf.pack()
    self.frameButton.pack()
    
    #labels para rotular os atributos/pack
    self.labelNome = tk.Label(self.frameNome,text="Nome: ")
    self.labelEmail = tk.Label(self.frameEmail,text="Email: ")
    self.labelCpf = tk.Label(self.frameCpf,text="CPF: ")
    self.labelNome.pack(side="left")
    self.labelEmail.pack(side="left")  
    self.labelCpf.pack(side="left")  

    #inputs para armazenar as entradas nas variaveis
    self.inputNome = tk.Entry(self.frameNome, width=20)
    self.inputNome.pack(side="left")
    self.inputEmail = tk.Entry(self.frameEmail, width=20)
    self.inputEmail.pack(side="left")
    self.inputCpf = tk.Entry(self.frameCpf, width=20)
    self.inputCpf.pack(side="left")          

    #configuramos botões bindados com funções para cadastrar, limpar e fechar
    self.buttonSubmit = tk.Button(self.frameButton ,text="Cadastrar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.enterHandler)
  
    self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", controle.fechaHandler)

  #função para mostrar mensagem quando chamada 
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

#Definimos janela para consulta de clientes
class LimiteConsultaCliente(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x100')
    self.title("Consulta Cliente")
    self.controle = controle

    #frames para atributos/pack
    self.frameCpf = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameCpf.pack()
    self.frameButton.pack()

    #labels para rotular o atributo cpf
    self.labelCpf = tk.Label(self.frameCpf, text="CPF: ")
    self.labelCpf.pack(side="left")
    self.inputCpf = tk.Entry(self.frameCpf, width=20)
    self.inputCpf.pack(side="left")

    #botão bindado para a função de consultar clientes
    self.buttonSubmit = tk.Button(self.frameButton, text="Consultar")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.consultaHandler)

    # botão para fechar a janela
    self.buttonFecha = tk.Button(self.frameButton, text="Fechar")
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", controle.fechaHandlercons)

  #Função para mostrar mensagem quando chamada
  def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

#Controller do Cliente e função para salvar em arquivo(pickle)
class CtrlCliente():       
  def __init__(self):
    if not os.path.isfile("cliente.pickle"):
      self.listaCliente =  []
    else:
      with open("cliente.pickle", "rb") as f:
        self.listaCliente = pickle.load(f)
  
  def salvaClientes(self):
    if len(self.listaCliente) != 0:
      with open("cliente.pickle","wb") as f:
          pickle.dump(self.listaCliente, f)

  def cadastraCliente(self):
    self.limiteCli = LimiteCadastraCliente(self)
    
        
    cpf = self.limiteCli.inputCpf.get()
    cliente = self.verificaCliente(cpf)
    return cliente is not None
  
  def consultaCliente(self):
        self.limiteConsCli = LimiteConsultaCliente(self)
  
  #Consulta cliente a partir do cpf
  def consultaHandler(self, event):
        cpf = self.limiteConsCli.inputCpf.get()
        cliente = self.verificaCliente(cpf)
        if cliente is not None:
            msg = f"Nome: {cliente.nome}\nEmail: {cliente.email}\nCPF: {cliente.cpf}"
        else:
            msg = "CPF não encontrado."
        self.limiteConsCli.mostraJanela('Consulta', msg)

  def verificaCliente(self, cpf):
    for cliente in self.listaCliente:
      if cliente.cpf == cpf:
        return cliente
    return None

  #enterHandler para usar get(), armazenar em variaveis, criar objeto e appendar
  def enterHandler(self, event):
    nome = self.limiteCli.inputNome.get()
    email = self.limiteCli.inputEmail.get()
    cpf = self.limiteCli.inputCpf.get()
    clientes = Cliente(nome, email, cpf)
    self.listaCliente.append(clientes)
    self.limiteCli.mostraJanela('Sucesso!', 'Cliente cadastrado com sucesso')
    self.clearHandler(event)
  
  #limpa campos
  def clearHandler(self, event):
    self.limiteCli.inputNome.delete(0, len(self.limiteCli.inputNome.get()))
    self.limiteCli.inputEmail.delete(0, len(self.limiteCli.inputEmail.get()))
    self.limiteCli.inputCpf.delete(0, len(self.limiteCli.inputCpf.get()))

  #fecha janelas
  def fechaHandler(self, event):
    self.limiteCli.destroy()
    
  def fechaHandlercons(self,event):
    self.limiteConsCli.destroy()
  
  #Mostra em janela os clientes cadastrados
  def mostraHandler(self,event):
    msg = "Clientes cadastrados: \n"
    for cliente in self.listaCliente:
            msg += "Nome: " + cliente.nome + " | E-mail: " + cliente.email + " | CPF: " + cliente.cpf + "\n"
    self.limiteConsCli.mostraJanela('Sucesso!', msg )
      