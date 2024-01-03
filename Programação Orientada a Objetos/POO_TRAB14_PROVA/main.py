import tkinter as tk
from tkinter import messagebox
import orientador as orient
import tfg

class LimitePrincipal():
    def __init__(self, root, controle):
        self.controle = controle
        self.root = root
        self.root.geometry('300x250')
        self.menubar = tk.Menu(self.root)        
        self.orientadorMenu = tk.Menu(self.menubar)
        self.tfgMenu = tk.Menu(self.menubar)
        self.turmaMenu = tk.Menu(self.menubar)     

        self.orientadorMenu.add_command(label="Insere", \
                    command=self.controle.insereOrientador)
        self.orientadorMenu.add_command(label="Mostra", \
                    command=self.controle.mostraOrientador)
        self.menubar.add_cascade(label="Orientador", \
                    menu=self.orientadorMenu)

        self.tfgMenu.add_command(label="Insere", \
                    command=self.controle.insereTfg)
        self.tfgMenu.add_command(label="Mostra Aprovados", \
                    command=self.controle.mostraTfgAprov)
        self.tfgMenu.add_command(label="Mostra Reprovados", \
                    command=self.controle.mostraTfgReprov)                  
        self.menubar.add_cascade(label="TFG", \
                    menu=self.tfgMenu)    

        self.root.config(menu=self.menubar)

      
class ControlePrincipal():       
    def __init__(self):
        self.root = tk.Tk()

        self.ctrlOrientador = orient.CtrlOrientador()
        self.ctrlTfg = tfg.CtrlTfg(self)

        self.limite = LimitePrincipal(self.root, self) 

        self.root.title("TFG")
        # Inicia o mainloop
        self.root.mainloop()
       
    def insereOrientador(self):
        self.ctrlOrientador.insereOrientador()

    def mostraOrientador(self):
        self.ctrlOrientador.mostraOrientador()

    def insereTfg(self):
        self.ctrlTfg.insereTfg()

    def mostraTfgAprov(self):
        self.ctrlTfg.mostraTfgAprov()

    def mostraTfgReprov(self):
        self.ctrlTfg.mostraTfgReprov()

if __name__ == '__main__':
    c = ControlePrincipal()