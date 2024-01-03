import tkinter as tk
import produto as prod
import cupom 
import cliente

class LimitePrincipal():
  def __init__(self, root, controle):
    self.controle = controle
    self.root = root

    self.root.geometry('450x250') #Ajustamos a resolução de proporção da janela

    self.menubar = tk.Menu(self.root)       #Definimos o menubar 
    self.produtoMenu = tk.Menu(self.menubar)  #Criamos variações para o menubar
    self.clienteMenu = tk.Menu(self.menubar)  #Criamos variações para o menubar 
    self.cupomMenu = tk.Menu(self.menubar)    #Criamos variações para o menubar
    self.sairMenu = tk.Menu(self.menubar)     #Criamos variações para o menubar
    self.faturamentoMenu = tk.Menu(self.menubar)#Criamos variações para o menubar

    #Menu Produto
    #Organizamos os comandos de clique e passamos as funções para cadastrar, consultar, alterar e remover os produtos
    self.produtoMenu.add_command(label="Cadastrar Carnes", command=self.controle.cadastraProduto)
    self.produtoMenu.add_command(label="Consultar Carnes", command=self.controle.consultaProduto)
    self.produtoMenu.add_command(label="Alterar Carnes", command=self.controle.alteraProduto)
    self.produtoMenu.add_command(label="Remover Carnes", command=self.controle.removeProduto)
    self.menubar.add_cascade(label="Produto", menu=self.produtoMenu)

    #Menu Cliente
    #Organizamos os comandos de clique e passamos as funções para cadastrar e consultar clientes do sistema
    self.clienteMenu.add_command(label="Cadastrar Cliente", command=self.controle.cadastraCliente)
    self.clienteMenu.add_command(label="Consultar Cliente", command=self.controle.consultaCliente)
    self.menubar.add_cascade(label="Clientes", menu=self.clienteMenu) 


    #Menu Cupom Fiscal
    #Organizamos os comandos de clique e passamos as funções para cadastrar cupons fiscais e para exibí-los
    self.cupomMenu.add_command(label="Cadastra", command=self.controle.cadastraCupom)
    self.cupomMenu.add_command(label="Exibir Nota", command=self.controle.exibirNota)
    self.menubar.add_cascade(label="Cupom Fiscal", menu=self.cupomMenu) 

    #Menu Faturamento
    #Organizamos os comandos de clique e passamos as funções para faturamentos
    self.faturamentoMenu.add_command(label="Por Produto", command=self.controle.faturamentoProduto)
    self.faturamentoMenu.add_command(label="Por Cliente", command=self.controle.faturamentoCliente)
    self.faturamentoMenu.add_command(label="Por Período", command=self.controle.faturamentoPeriodo)
    self.faturamentoMenu.add_command(label="Cliente e data", command=self.controle.consultaVendasCliente)
    self.faturamentoMenu.add_command(label="Produtos mais vendidos", command=self.controle.produtosMaisVendidos)
    self.menubar.add_cascade(label="Faturamento", menu=self.faturamentoMenu)

    #Menu Sair - Salvar Dados(pickle)
    self.sairMenu.add_command(label="Salva", command=self.controle.salvaDados)
    self.menubar.add_cascade(label="Sair", menu=self.sairMenu)      

    self.root.config(menu=self.menubar)
    
class ControlePrincipal():       
  def __init__(self):
      self.root = tk.Tk()

      self.ctrlProduto = prod.CtrlProduto()
      self.ctrlCupom = cupom.CtrlCupom(self)
      self.ctrlCliente = cliente.CtrlCliente()
      self.limite = LimitePrincipal(self.root, self) 

      self.root.title("Gerenciamento de açougue - UNIFEI")
      # Inicia o mainloop
      self.root.mainloop()
      
  def cadastraProduto(self):
    self.ctrlProduto.cadastraProduto()

  def consultaProduto(self):
    self.ctrlProduto.consultaProduto()

  def alteraProduto(self):
    self.ctrlProduto.alteraProduto()
    
  def removeProduto(self):
    self.ctrlProduto.removeProduto()
  
  def cadastraCliente(self):
    self.ctrlCliente.cadastraCliente()

  def verificaCliente(self):
    self.ctrlCliente.verificaCliente()

  def consultaCliente(self):
    self.ctrlCliente.consultaCliente()
    
  def cadastraCupom(self):
    self.ctrlCupom.cadastraCupom()
  
  def exibirNota(self):
    self.ctrlCupom.exibirNota()

  def faturamentoProduto(self):
    self.ctrlCupom.faturamentoProduto()

  def faturamentoCliente(self):
    self.ctrlCupom.faturamentoCliente()

  def faturamentoPeriodo(self):
    self.ctrlCupom.faturamentoPeriodo()
    
  def consultaVendasCliente(self):
    self.ctrlCupom.consultaVendasCliente()

  def produtosMaisVendidos(self):
    self.ctrlCupom.produtosMaisVendidos()
    
  def salvaDados(self):
    self.ctrlProduto.salvaProdutos()
    self.ctrlCliente.salvaClientes()
    self.ctrlCupom.salvaCupons()
    self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()