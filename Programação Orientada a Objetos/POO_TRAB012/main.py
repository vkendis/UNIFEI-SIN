#vinicius Kendi Sasaki
#2023013498
#Trabalho Campeonato de Futebol
import tkinter as tk
from tkinter import messagebox
import estudante_curso as est_cur
import equipe as equi

class LimitePrincipal():
  def __init__(self, root, controle):
    self.controle = controle
    self.root = root
    self.root.geometry('350x250')
    self.menubar = tk.Menu(self.root)        
    self.sairMenu = tk.Menu(self.menubar) 

    self.menubar.add_command(label="Criar Equipe", command=self.controle.cadastraEquipe)
    self.menubar.add_command(label="Consultar Equipe", command=self.controle.consultaEquipe)
    self.menubar.add_command(label="Imprimir dados", command=self.controle.imprimeDados)

  
    self.sairMenu.add_command(label="Salva", \
                    command=self.controle.salvaDados)
    self.menubar.add_cascade(label="Sair", \
                    menu=self.sairMenu)      

    self.root.config(menu=self.menubar)
    
class ControlePrincipal():       
  def __init__(self):
    self.root = tk.Tk()

    self.ctrlEstCur = est_cur.CtrlEstudanteCurso()
    self.ctrlEquipe = equi.CtrlEquipe(self)

    self.limite = LimitePrincipal(self.root, self) 

    self.root.title("⚽ Campeonato Futebol - UNIFEI ⚽")
    
    # Inicia o mainloop
    self.root.mainloop()
      
  def cadastraEquipe(self):
    self.ctrlEquipe.cadastraEquipe()

  def consultaEquipe(self):
    self.ctrlEquipe.consultaEquipe()

  def imprimeDados(self):
    self.ctrlEquipe.dadosCampeonato()
  
  def salvaDados(self):
    self.ctrlEquipe.salvaEquipe()
    self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()