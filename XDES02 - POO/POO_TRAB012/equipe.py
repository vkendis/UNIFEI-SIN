import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Equipe:
  def __init__(self, curso, listaEstEquipe):
    self.curso = curso
    self.listaEstEquipe = listaEstEquipe

  @property
  def curso(self):
    return self.__curso
  
  @curso.setter
  def curso(self, curso):
    self.__curso = curso
  
  @property
  def listaEstEquipe(self):
    return self.__listaEstEquipe
  
  @listaEstEquipe.setter
  def listaEstEquipe(self, listaEstEquipe):
    self.__listaEstEquipe = listaEstEquipe
  
  def estsEquipe(self):
    str = "Estudantes da Equipe de {}: \n".format(self.curso.sigla)

    for est in self.listaEstEquipe:
      str += "- " + est.nome + "\n"
    
    return str

class LimiteCadastraEquipe(tk.Toplevel):
  def __init__(self, controle, cursos):
    tk.Toplevel.__init__(self)
    self.geometry('250x250')
    self.title("Nova Equipe")
    self.controle = controle

    self.frameCursos = tk.Frame(self)
    self.frameEst = tk.Frame(self)
    self.frameButtonAcao = tk.Frame(self)
    self.frameButtonAux = tk.Frame(self)
    self.frameCursos.pack()
    self.frameEst.pack()
    self.frameButtonAcao.pack()
    self.frameButtonAux.pack()

    # Cursos
    self.labelCursos = tk.Label(self.frameCursos,text="Curso: ")
    self.labelCursos.pack(side="left")
    self.escolhaCurso = tk.StringVar()
    self.comboboxCursos = ttk.Combobox(self.frameCursos, width = 25 ,values=cursos, textvariable = self.escolhaCurso)
    self.comboboxCursos.pack(side="left")
    self.comboboxCursos.bind("<<ComboboxSelected>>", self.controle.bloqueiaCombo)

    # Estudante
    self.labelEst = tk.Label(self.frameEst,text="Estudante: ")
    self.labelEst.pack(side="left")
    self.inputEst = tk.Entry(self.frameEst, width=20)
    self.inputEst.pack(side="left")  

    self.buttonAdd = tk.Button(self.frameButtonAcao ,text="Adicionar Estudante")      
    self.buttonAdd.pack(side="left")
    self.buttonAdd.bind("<Button>", controle.addEst)    
  
    self.buttonSubmit = tk.Button(self.frameButtonAcao ,text="Criar Equipe")      
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.enterHandler)
  
    self.buttonClear = tk.Button(self.frameButtonAux ,text="Clear")      
    self.buttonClear.pack(side="left")
    self.buttonClear.bind("<Button>", controle.clearHandler)  

    self.buttonFecha = tk.Button(self.frameButtonAux ,text="Fechar")      
    self.buttonFecha.pack(side="left")
    self.buttonFecha.bind("<Button>", controle.fechaHandler)

  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class LimiteDadosCampeonato(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('500x200')
    self.title("Informações do Campeonato")
    self.ctrl = controle

    self.frameInfos = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameInfos.pack()
    self.frameButton.pack()

    self.textInfos = tk.Text(self.frameInfos, height=10,width=60)
    self.textInfos.pack()
    self.textInfos.config(state=tk.DISABLED) 

    self.buttonFechar = tk.Button(self.frameButton ,text="Fechar")      
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaInfos)

class LimiteConsultaEquipe(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('400x400')
    self.title("Consultar Equipes")
    self.ctrl = controle

    self.frameSigla = tk.Frame(self)
    self.frameEquipe = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameSigla.pack()
    self.frameEquipe.pack()
    self.frameButton.pack()

    self.labelSigla = tk.Label(self.frameSigla,text="Sigla: ")
    self.labelSigla.pack(side="left")
    self.inputSigla = tk.Entry(self.frameSigla, width=20)
    self.inputSigla.pack(side="left")

    self.textEquipe = tk.Text(self.frameEquipe, height=20,width=40)
    self.textEquipe.pack()
    self.textEquipe.config(state=tk.DISABLED) 

    self.buttonConsultar = tk.Button(self.frameButton ,text="Buscar Equipe")      
    self.buttonConsultar.pack(side="left")
    self.buttonConsultar.bind("<Button>", controle.exibeEquipe)  
    
class CtrlEquipe():       
  def __init__(self, controlePrincipal):
    self.ctrlPrin = controlePrincipal
    self.listaEstEquipe = []
    if not os.path.isfile("equipes.pickle"):
      self.listaEquipes =  []
    else:
      with open("equipes.pickle", "rb") as f:
        self.listaEquipes = pickle.load(f)
  
  def salvaEquipe(self):
    if len(self.listaEquipes) != 0:
      with open("equipes.pickle","wb") as f:
        pickle.dump(self.listaEquipes, f)

  def cadastraEquipe(self):
    self.listaEstEquipe = []
    self.limiteCad = LimiteCadastraEquipe(self, self.ctrlPrin.ctrlEstCur.listaNomesCursos())
  
  def dadosCampeonato(self):
    self.limiteDados = LimiteDadosCampeonato(self)
    self.processaDados()
  
  def consultaEquipe(self):
    self.limiteCons = LimiteConsultaEquipe(self)
  
  def bloqueiaCombo(self, event):
    self.limiteCad.comboboxCursos.config(state='disable')

  def addEst(self, event):
    curso = self.limiteCad.comboboxCursos.get()
    matricula = self.limiteCad.inputEst.get()

    if int(matricula) in self.ctrlPrin.ctrlEstCur.listaNroMatric():
      for est in self.ctrlPrin.ctrlEstCur.listaEstudante:
        if est.nroMatric == int(matricula):
          if est in self.listaEstEquipe:
            self.limiteCad.mostraJanela("Ops!", "Estudante já incluído!")
          else:
            if est.curso.nome == curso:
              self.listaEstEquipe.append(est)
              self.limiteCad.mostraJanela("Sucesso!", "Estudante incluído com sucesso!")
            else:
              self.limiteCad.mostraJanela("Ops!", "Estudante não pertence a este curso!")
    else:
      self.limiteCad.mostraJanela("Erro!!!", "Matrícula Inválida")
  
  def enterHandler(self, event):
    curso = self.ctrlPrin.ctrlEstCur.getCurso(self.limiteCad.comboboxCursos.get())
    comEquipe = 0

    for eq in self.listaEquipes:
      if eq.curso.sigla == curso.sigla:
        comEquipe = 1

    if comEquipe == 0:
      equipe = Equipe(curso, self.listaEstEquipe)

      self.listaEquipes.append(equipe)
      self.limiteCad.mostraJanela('Sucesso!', 'Equipe cadastrada com sucesso!')
    else:
      self.limiteCad.mostraJanela('Ops!', 'Este curso já possui uma equipe cadastrada!')

    self.listaEstEquipe = []
    self.clearHandler(event)
  
  def clearHandler(self, event):
    self.limiteCad.comboboxCursos.config(state='normal')
    self.limiteCad.comboboxCursos.set("---")
    self.listaEstEquipe = []
    self.limiteCad.inputEst.delete(0, len(self.limiteCad.inputEst.get()))

  def fechaHandler(self, event):
    self.limiteCad.destroy()
  
  def exibeEquipe(self, event):
    sigla = self.limiteCons.inputSigla.get()
    comEquipe = 0
    
    self.limiteCons.textEquipe.config(state='normal')
    self.limiteCons.textEquipe.delete("1.0", tk.END)
    
    if sigla in self.ctrlPrin.ctrlEstCur.listaSiglasCursos():
      for equipe in self.listaEquipes:
        if equipe.curso.sigla == sigla:
          self.limiteCons.textEquipe.insert(1.0, equipe.estsEquipe())
          comEquipe = 1
      if comEquipe == 0:
        self.limiteCons.textEquipe.insert(1.0, "Não existe equipe desse curso")
    else:
      self.limiteCons.textEquipe.insert(1.0, "Esta sigla de curso não existe")

    self.limiteCons.textEquipe.config(state = 'disable')
  
  def fechaInfos(self, event):
    self.limiteDados.destroy()
  
  def processaDados(self):
    numEquipes = len(self.listaEquipes)
    numEsts = 0
    media = 0

    for equipe in self.listaEquipes:
      numEsts += len(equipe.listaEstEquipe)
    
    media = numEsts/numEquipes

    self.limiteDados.textInfos.config(state='normal')
    self.limiteDados.textInfos.delete(1.0, tk.END)

    str = "Dados estatísticos do Campeonato:\n- Número de equipes: {} equipes\n- Número total de estudantes: {} estudantes\n- Média de estudantes por equipe: {} estudantes".format(numEquipes, numEsts, media)

    self.limiteDados.textInfos.insert("1.0", str)
    self.limiteDados.textInfos.config(state='disable')


        