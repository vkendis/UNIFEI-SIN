import tkinter as tk
from tkinter import messagebox

class Orientador:

    def __init__(self, email, nome):
        self.__email = email
        self.__nome = nome

    @property
    def email(self):
        return self.__email
    
    @property
    def nome(self):
        return self.__nome

class LimiteInsereOrientadores(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x100')
        self.title("Orientador")
        self.controle = controle

        self.frameEmail = tk.Frame(self)
        self.frameNome = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameEmail.pack()
        self.frameNome.pack()
        self.frameButton.pack()
      
        self.labelNro = tk.Label(self.frameEmail,text="e-mail: ")
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNro.pack(side="left")
        self.labelNome.pack(side="left")  

        self.inputEmail = tk.Entry(self.frameEmail, width=20)
        self.inputEmail.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")             
      
        self.buttonSubmit = tk.Button(self.frameButton ,text="Enter")      
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

class LimiteMostraOrientadores():
    def __init__(self, str):
        messagebox.showinfo('Lista de alunos', str)

      
class CtrlOrientador():       
    def __init__(self):
        self.listaOrientadores = [
            Orientador('baldochi@unifei.edu.br', 'Laercio'),
            Orientador('melise@unifei.edu.br', 'Melise'),
            Orientador('adler@unifei.edu.br', 'Adler'),
            Orientador('minoru@unifei.edu.br', 'Minoru')
        ]

    def getOrientador(self, nome):
        orientRet = None
        for orient in self.listaOrientadores:
            if orient.nome == nome:
                orientRet = orient
        return orientRet
    
    def getListaNomeOrient(self):
        listaNome = []
        for orient in self.listaOrientadores:
            listaNome.append(orient.nome)
        return listaNome

    def insereOrientador(self):
        self.limiteIns = LimiteInsereOrientadores(self) 

    def mostraOrientador(self):
        str = 'e-mail -- Nome\n'
        for orient in self.listaOrientadores:
            str += orient.email + ' -- ' + orient.nome + '\n'       
        self.limiteLista = LimiteMostraOrientadores(str)

    def enterHandler(self, event):
        email = self.limiteIns.inputEmail.get()
        nome = self.limiteIns.inputNome.get()
        orientador = Orientador(email, nome)
        self.listaOrientadores.append(orientador)
        self.limiteIns.mostraJanela('Sucesso', 'Orientador cadastrado com sucesso')
        self.clearHandler(event)

    def clearHandler(self, event):
        self.limiteIns.inputEmail.delete(0, len(self.limiteIns.inputEmail.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

    def fechaHandler(self, event):
        self.limiteIns.destroy()
    