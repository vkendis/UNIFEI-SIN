#Vinícius Kendi Sasaki
#2023013498

import tkinter as tk
from tkinter import messagebox
import jogo

class LimitePrincipal():
  def __init__(self, root, controle):
    self.controle = controle
    self.root = root
    self.root.geometry('400x300')
    self.root.configure(bg='yellowgreen')
    self.root.config(cursor="hand2")
    self.root.resizable(width=True, height=True)
    self.menubar = tk.Menu(self.root)        
    self.jogoMenu = tk.Menu(self.menubar)
    self.sairMenu = tk.Menu(self.menubar) 

    #Menu jogo
    self.jogoMenu.add_command(label="Cadastrar", command=self.controle.cadastraJogo)
    self.jogoMenu.add_command(label="Avaliar", command=self.controle.avaliaJogo)
    self.jogoMenu.add_command(label="Consultar", command=self.controle.consultaJogo)
    self.menubar.add_cascade(label="Jogo", menu=self.jogoMenu)

    #Menu Sair - Salvar Dados
    self.sairMenu.add_command(label="Salva", \
                    command=self.controle.salvaDados)
    self.menubar.add_cascade(label="Sair", \
                    menu=self.sairMenu)      

    self.root.config(menu=self.menubar)
    
class ControlePrincipal():       
  def __init__(self):
    self.root = tk.Tk()

    self.ctrlJogo = jogo.CtrlJogo()

    self.limite = LimitePrincipal(self.root, self) 

    self.root.title("🎮 - Avaliador de jogos")
    
    # Inicia o mainloop
    self.root.mainloop()
      
  def cadastraJogo(self):
    self.ctrlJogo.cadastraJogo()

  def consultaJogo(self):
    self.ctrlJogo.consultaJogo()

  def avaliaJogo(self):
    self.ctrlJogo.avaliaJogo()
  
  def salvaDados(self):
    self.ctrlJogo.salvaJogos()
    self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()