#Vinícius Kendi Sasaki
#2023013498

import tkinter as tk
from tkinter import messagebox
from tkinter import simpledialog

class ModelCliente():
    def __init__(self, codigo, nome, email):
        self.__nome = nome
        self.__email = email
        self.__codigo = codigo
    @property
    def nome(self):
        return self.__nome

    @property
    def email(self):
        return self.__email
    
    @property
    def codigo(self):
        return self.__codigo

class View():
    def __init__(self, master, controller):
        self.controller = controller
        self.janela = tk.Frame(master)
        self.janela.pack()
        self.frame1 = tk.Frame(self.janela)
        self.frame2 = tk.Frame(self.janela)
        self.frame3 = tk.Frame(self.janela)
        self.frame1.pack()
        self.frame2.pack()
        self.frame3.pack()

        self.labelInfo1 = tk.Label(self.frame1,text="Nome: ")
        self.labelInfo2 = tk.Label(self.frame2,text="Email: ")
        self.labelInfo3 = tk.Label(self.frame3,text="Código: ")
        self.labelInfo1.pack(side="left")
        self.labelInfo2.pack(side="left") 
        self.labelInfo3.pack(side="left")   

        self.inputText1 = tk.Entry(self.frame1, width=20)
        self.inputText1.pack(side="left")
        self.inputText2 = tk.Entry(self.frame2, width=20)
        self.inputText2.pack(side="left")             
        self.inputText3 = tk.Entry(self.frame3, width=20)
        self.inputText3.pack(side="left")


        self.buttonSubmit = tk.Button(self.janela,text="Salva")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controller.salvaHandler)
      
        self.buttonClear = tk.Button(self.janela,text="Limpa")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controller.clearHandler)            

        self.buttonMostra = tk.Button(self.janela,text="Mostra")      
        self.buttonMostra.pack(side="left")
        self.buttonMostra.bind("<Button>", controller.mostraHandler)

        self.buttonConsulta = tk.Button(self.janela,text="Consulta")      
        self.buttonConsulta.pack(side="left")
        self.buttonConsulta.bind("<Button>", controller.consultaHandler)

        
    def mostraJanela(self, titulo, mensagem):
        messagebox.showinfo(titulo, mensagem)
      
class Controller():       
    def __init__(self):
        self.root = tk.Tk()
        self.root.geometry('300x100')
        self.listaClientes = []

        # Cria a view passando referência da janela principal e
        # de si próprio (controlador)
        self.view = View(self.root, self) 

        self.root.title("Exemplo MVC")
        # Inicia o mainloop
        self.root.mainloop()

    def salvaHandler(self, event):
        nomeCli = self.view.inputText1.get()
        emailCli = self.view.inputText2.get()
        codCli = self.view.inputText3.get()
        cliente = ModelCliente(codCli, nomeCli, emailCli)
        self.listaClientes.append(cliente)
        self.view.mostraJanela('Sucesso', 'Cliente cadastrado com sucesso')
        self.clearHandler(event)

    def clearHandler(self, event):
        self.view.inputText1.delete(0, len(self.view.inputText1.get()))
        self.view.inputText2.delete(0, len(self.view.inputText2.get()))
        self.view.inputText3.delete(0, len(self.view.inputText3.get())) 

    
    def mostraHandler(self,event):
        msg = 'Clientes Cadastrados: \n'
        for cliente in self.listaClientes:
            msg += cliente.nome + ' - ' + cliente.email + ' - ' + cliente.codigo + '\n'
        self.view.mostraJanela('Lista de clientes', msg)
        #Caso nao houver a linha 84, o conteúdo nao sera exibido apos apertar 
        
    def consultaHandler(self, event):
        

        answer = simpledialog.askstring("Input", "Digite o código para Consulta:")
                                       

        cliente_encontrado = None
        for cliente in self.listaClientes:
            if cliente.codigo == answer:
                cliente_encontrado = cliente
                break

        if cliente_encontrado is not None:
            msg = f'Cliente encontrado: \nNome: {cliente_encontrado.nome}\nEmail: {cliente_encontrado.email}\nCódigo: {cliente_encontrado.codigo}'
            self.view.mostraJanela('Consulta de Cliente', msg)
        else:
            self.view.mostraJanela('Erro', 'Código não encontrado')




if __name__ == '__main__':
    c = Controller()