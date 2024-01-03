import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

class Tfg:

    def __init__(self, titulo, aluno, orientador, notaMonog, notaApres):
        self.__titulo = titulo
        self.__aluno = aluno
        self.__orientador = orientador
        self.notaMonog = notaMonog
        self.notaApres = notaApres

    @property
    def titulo(self):
        return self.__titulo
    
    @property
    def aluno(self):
        return self.__aluno
    
    @property
    def orientador(self):
        return self.__orientador
    
    @property
    def notaMonog(self):
        return self.__notaMonog
    
    @property
    def notaApres(self):
        return self.__notaApres
    
    @notaMonog.setter
    def notaMonog(self, valor):
        if valor < 1 or valor > 10:
            raise ValueError("Valor inválido: {}".format(valor))
        else:
            self.__notaMonog = valor            

    @notaApres.setter
    def notaApres(self, valor):
        if valor < 1 or valor > 10:
            raise ValueError("Valor inválido: {}".format(valor))
        else:
            self.__notaApres = valor 

    def getOrientador(self):
        str = "Título: " + self.__titulo + "\n"
        str += "Aluno: " + self.__aluno + "\n"
        str += "Aluno: " + self.__aluno + "\n"

class LimiteInsereTfg(tk.Toplevel):
    def __init__(self, controle, listaNomeProf):

        tk.Toplevel.__init__(self)
        self.geometry('300x170')
        self.title("Cadastro de TFG")
        self.controle = controle

        self.frameTitulo = tk.Frame(self)
        self.frameAluno = tk.Frame(self)
        self.frameOrient = tk.Frame(self)
        self.frameNotaMonong = tk.Frame(self)
        self.frameNotaApres = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameTitulo.pack()
        self.frameAluno.pack()
        self.frameOrient.pack()
        self.frameNotaMonong.pack() 
        self.frameNotaApres.pack()
        self.frameButton.pack()        

        self.labelTitulo = tk.Label(self.frameTitulo,text="Título do TFG: ")
        self.labelTitulo.pack(side="left")
        self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
        self.inputTitulo.pack(side="left")

        self.labelNomeAluno = tk.Label(self.frameAluno,text="Nome do aluno: ")
        self.labelNomeAluno.pack(side="left")
        self.inputNomeAluno = tk.Entry(self.frameAluno, width=20)
        self.inputNomeAluno.pack(side="left")

        self.labelOrient = tk.Label(self.frameOrient,text="Escolha o orientador: ")
        self.labelOrient.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameOrient, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNomeProf
          
        self.labelNotaMonog = tk.Label(self.frameNotaMonong,text="Nota monografia: ")
        self.labelNotaMonog.pack(side="left")
        self.inputNotaMonog = tk.Entry(self.frameNotaMonong, width=20)
        self.inputNotaMonog.pack(side="left")

        self.labelNotaApres = tk.Label(self.frameNotaApres,text="Nota apresentação: ")
        self.labelNotaApres.pack(side="left")
        self.inputNotaApres = tk.Entry(self.frameNotaApres, width=20)
        self.inputNotaApres.pack(side="left")

        self.buttonInsere = tk.Button(self.frameButton ,text="Insere TFG")           
        self.buttonInsere.pack(side="left")
        self.buttonInsere.bind("<Button>", controle.criaTfg)

        self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.limpaForm)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaJanela)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg) 

class LimiteMostraTfgs():
    def __init__(self, titulo, corpo):
        messagebox.showinfo(titulo, corpo)

class CtrlTfg():       
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal
        self.listaTfgs = []

    def insereTfg(self):        
        listaOrient = self.ctrlPrincipal.ctrlOrientador.getListaNomeOrient()
        self.limiteIns = LimiteInsereTfg(self, listaOrient)        

    def criaTfg(self, event):
        titulo = self.limiteIns.inputTitulo.get()
        aluno = self.limiteIns.inputTitulo.get()
        nomeOrient = self.limiteIns.escolhaCombo.get()
        orient = self.ctrlPrincipal.ctrlOrientador.getOrientador(nomeOrient)
        notaMonog = float(self.limiteIns.inputNotaMonog.get())
        notaApres = float(self.limiteIns.inputNotaMonog.get())

        try:
            tfg = Tfg(titulo, aluno, orient, notaMonog, notaApres)
            self.listaTfgs.append(tfg)            
            self.limiteIns.mostraJanela('Sucesso', 'TFG cadastrado com sucesso')
            self.limpaForm(event)
        except ValueError as error:
            self.limiteIns.mostraJanela('Erro', error)  

    def limpaForm(self, event):
        self.limiteIns.inputTitulo.delete(0, len(self.limiteIns.inputTitulo.get()))
        self.limiteIns.inputNomeAluno.delete(0, len(self.limiteIns.inputNomeAluno.get()))
        self.limiteIns.inputNotaMonog.delete(0, len(self.limiteIns.inputNotaMonog.get()))
        self.limiteIns.inputNotaApres.delete(0, len(self.limiteIns.inputNotaApres.get()))
        self.limiteIns.escolhaCombo.set('')          
 
    def fechaJanela(self, event):
        self.limiteIns.destroy()
             
    def mostraTfgAprov(self):
        st = ""
        print(len(self.listaTfgs))
        for tfg in self.listaTfgs:
            nota = tfg.notaMonog * 0.7 + tfg.notaApres * 0.3
            if nota >= 6:
                st += "Título: " + tfg.titulo + "\n"
                st += "Aluno: " + tfg.aluno + "\n"
                st += "Orientador: " + tfg.orientador.nome + "\n"
                st += "Nota final: " + str(round(nota, 2)) + "\n"
                st += "----------\n"
        if len(st) == 0:
            st = "Não há alunos aprovados"
        self.limiteMostra = LimiteMostraTfgs("TFGs aprovados", st)

    def mostraTfgReprov(self):
        st = ""
        print(len(self.listaTfgs))
        for tfg in self.listaTfgs:
            nota = tfg.notaMonog * 0.7 + tfg.notaApres * 0.3
            if nota < 6:
                st += "Título: " + tfg.titulo + "\n"
                st += "Aluno: " + tfg.aluno + "\n"
                st += "Orientador: " + tfg.orientador.nome + "\n"
                st += "Nota final: " + str(round(nota, 2)) + "\n"
                st += "----------\n"
        if len(st) == 0:
            st = "Não há alunos reprovados"
        self.limiteMostra = LimiteMostraTfgs("TFGs reprovados", st)        