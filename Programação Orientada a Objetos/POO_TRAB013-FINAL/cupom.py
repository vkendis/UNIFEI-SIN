import tkinter as tk
from tkinter import messagebox
import os.path
import pickle
from datetime import datetime
import tkinter.simpledialog as simpledialog

#Definimos a classe cupom fiscal
class CupomFiscal:
  def __init__(self, nroCupom, itensCupom, cpf, qtd, data_emissao=None):
    self.nroCupom = nroCupom
    self.__itensCupom = itensCupom
    self.__cpf = cpf
    self.__qtd = qtd
    self.data_emissao = data_emissao if data_emissao else datetime.now()

  @property
  def data_emissao(self):
    return self.__data_emissao
  
  @data_emissao.setter
  def data_emissao(self, data_emissao):
    self.__data_emissao = data_emissao
  
  @property
  def nroCupom(self):
    return self.__nroCupom
  
  @nroCupom.setter
  def nroCupom(self, nroCupom):
    self.__nroCupom = nroCupom
  
  @property
  def itensCupom(self):
    return self.__itensCupom
  
  @property
  def cpf(self):
    return self.__cpf
  
  @property
  def qtd(self):
    return self.__qtd

#Definimos a janela para cadastramento de cupom fiscal
class LimiteCadastraCupomFiscal(tk.Toplevel):
  def __init__(self, controle, listaCodsProds):
    tk.Toplevel.__init__(self)
    self.geometry('250x250')
    self.title("Novo Cupom Fiscal")
    self.controle = controle

    #frames pra cupom/pack
    self.frameNroCupom = tk.Frame(self)
    self.frameItensCupom = tk.Frame(self)
    self.framecpf = tk.Frame(self)
    self.frameqtd = tk.Frame(self)
    self.frameButton = tk.Frame(self)
    self.frameNroCupom.pack()
    self.frameItensCupom.pack()
    self.framecpf.pack()
    self.frameqtd.pack()
    self.frameButton.pack()

    #labels para rotular os atributos/pack
    self.labelNroCupom = tk.Label(self.frameNroCupom,text="Nro. Cupom: ")
    self.labelNroCupom.pack(side="left")
    self.inputNroCupom = tk.Entry(self.frameNroCupom, width=20)
    self.inputNroCupom.pack(side="left")

    self.labelitemCupom = tk.Label(self.frameItensCupom,text="Nro. Codigo: ")
    self.labelitemCupom.pack(side="left")
    self.inputitemCupom = tk.Entry(self.frameItensCupom, width=20)
    self.inputitemCupom.pack(side="left")  

    self.labelcpf = tk.Label(self.framecpf,text="Nro. CPF: ")
    self.labelcpf.pack(side="left")
    self.inputcpf = tk.Entry(self.framecpf, width=20)
    self.inputcpf.pack(side="left")  

    self.labelqtd = tk.Label(self.frameqtd,text="Quantidade em Kg: ")
    self.labelqtd.pack(side="left")
    self.inputqtd = tk.Entry(self.frameqtd, width=20)
    self.inputqtd.pack(side="left")  
         
    #Configuramos os botoes bindados para funções de inserir produtos e cadastrar cupom
    self.buttonInsere = tk.Button(self.frameButton ,text="Insere Produto")           
    self.buttonInsere.pack(side="left")
    self.buttonInsere.bind("<Button>", controle.insereProduto)

    self.buttonCria = tk.Button(self.frameButton ,text="Fechar Cupom")           
    self.buttonCria.pack(side="left")
    self.buttonCria.bind("<Button>", controle.criaCupom) 

  #Função que mostra mensagem quando chamada
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

#Definimos a janela para exibir cupons fiscais existentes
class LimiteExibeNota(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Exibir Nota Fiscal")
    self.controle = controle

    #frame para atributos/pack
    self.frameNumero = tk.Frame(self)
    self.frameNumero.pack()

    #label para rotular atributos/pack
    self.labelNumero = tk.Label(self.frameNumero, text="Número da Nota: ")
    self.labelNumero.pack(side="left")
    self.inputNumero = tk.Entry(self.frameNumero, width=20)
    self.inputNumero.pack(side="left")

    #configuramos botoes para bindar funcao de exibir notas
    self.buttonSubmit = tk.Button(self, text="Exibir")
    self.buttonSubmit.pack(side="left")
    self.buttonSubmit.bind("<Button>", controle.exibeNotaHandler)  

#Controller do cupom fiscal e configuração de pickle para armazenar em arquivo
class CtrlCupom():       
  def __init__(self,controlePrincipal):
    self.listaProdutosCupom = []
    self.ctrlPrincipal = controlePrincipal
    self.faturamentoPorProduto = {}
    if not os.path.isfile("cupom.pickle"):
      self.listaCupons =  []
    else:
      with open("cupom.pickle", "rb") as f:
        self.listaCupons= pickle.load(f)
  
  def salvaCupons(self):
    if len(self.listaCupons) != 0:
      with open("cupom.pickle","wb") as f:
        pickle.dump(self.listaCupons, f)

  def cadastraCupom(self):
    self.limiteCad = LimiteCadastraCupomFiscal(self, self.ctrlPrincipal.ctrlProduto.getListaCodigosProdutos())
    
  #Função para inserir produto à nota limitando a 10 quantidades por nota conforme solicitado
  def insereProduto(self, event):
    if len(self.listaProdutosCupom) >= 10:
        messagebox.showinfo("Limite Atingido", "Não é possível adicionar mais de 10 produtos por nota fiscal.")
        return

    cpf = self.limiteCad.inputcpf.get()
    cliente = self.ctrlPrincipal.ctrlCliente.verificaCliente(cpf)

    if cliente is None:
        resposta = messagebox.askyesno("Cliente não encontrado", "CPF não encontrado. Deseja cadastrar um novo cliente?")
        if resposta:
            self.ctrlPrincipal.ctrlCliente.cadastraCliente()
            # Depois do cadastro, verifica novamente se o cliente foi adicionado
            cliente = self.ctrlPrincipal.ctrlCliente.verificaCliente(cpf)
            if cliente is None:
                messagebox.showinfo("Erro", "Cupom não pode ser criado sem um cliente válido.")
                return

    codigo = self.limiteCad.inputitemCupom.get()
    qtd = float(self.limiteCad.inputqtd.get())
    prodRet = self.ctrlPrincipal.ctrlProduto.getProd(codigo)

    if prodRet is None:
        self.limiteCad.mostraJanela('Erro', 'Produto não encontrado')
    else:
        valorTotal = float(prodRet.valorUni) * qtd
        self.listaProdutosCupom.append((prodRet, qtd, valorTotal))
        self.limiteCad.mostraJanela('Produto Adicionado', f'Nome: {prodRet.desc}\nPreço: {prodRet.valorUni}\nQuantidade: {qtd}\nTotal: R$ {valorTotal:.2f}')

  #Funcao para criar cupom, cria objeto e appenda
  def criaCupom(self, event):
    nroCupom = self.limiteCad.inputNroCupom.get()
    cpf = self.limiteCad.inputcpf.get()
    cupom = CupomFiscal(nroCupom, self.listaProdutosCupom, cpf, len(self.listaProdutosCupom))
    self.listaCupons.append(cupom)
    self.limiteCad.mostraJanela('Sucesso', 'Cupom criado com sucesso')
    self.limiteCad.destroy()

  #Limpa a lista de produtos do cupom após a criação para que nao insira produtos repetidos
    self.listaProdutosCupom = []
  
  def verificaCliente(self, cpf):
    for cliente in self.ctrlPrincipal.ctrlCliente.listaCliente:
      if cliente.cpf == cpf:
        return cliente
    return None

  def exibeNotaHandler(self):
    numeroNota = simpledialog.askstring("Número da Nota", "Digite o número da nota fiscal:")

    nota = self.encontraNota(numeroNota)
    if nota:
        detalhesNota = self.formataDetalhesNota(nota)
        messagebox.showinfo("Detalhes da Nota", detalhesNota)
    else:
        messagebox.showinfo("Erro", "Nota fiscal não encontrada.")

  def exibirNota(self):
    self.exibeNotaHandler()

  def encontraNota(self, numeroNota):
    for nota in self.listaCupons:
        if nota.nroCupom == numeroNota:
            return nota
    return None

  def formataDetalhesNota(self, nota):
    detalhes = f"CPF: {nota.cpf}\n"
    cliente = self.ctrlPrincipal.ctrlCliente.verificaCliente(nota.cpf)
    detalhes += f"Nome do Cliente: {cliente.nome if cliente else 'Desconhecido'}\n"
    detalhes += f"Data de Emissão: {nota.data_emissao.strftime('%d/%m/%Y')}\n"
    detalhes += "Itens da Nota:\n"

    valorTotalNota = 0  
    for item in nota.itensCupom:
        produto, quantidade, valorTotal = item
        detalhes += f"- {produto.desc} | Qtd: {quantidade} Kg | Valor: R$ {valorTotal:.2f}\n"
        valorTotalNota += valorTotal  

    
    detalhes += f"\nValor Total da Nota: R$ {valorTotalNota:.2f}"
    return detalhes

  #Faturamento em reais do produto com codigo como parametro
  def faturamentoProduto(self):
    codigoProduto = simpledialog.askstring("Faturamento por Produto", "Digite o código do produto:")

    if not codigoProduto:
        messagebox.showinfo("Informação", "Nenhum código informado.")
        return

    faturamentoTotal = 0

    for cupom in self.listaCupons:
        for item in cupom.itensCupom:
            produto, _, valorTotal = item

            if produto.codigo == codigoProduto:  
                faturamentoTotal += valorTotal

    if faturamentoTotal > 0:
        messagebox.showinfo("Faturamento do Produto", f"Faturamento do produto {codigoProduto}: R$ {faturamentoTotal:.2f}")
    else:
        messagebox.showinfo("Faturamento do Produto", f"Nenhum faturamento registrado para o produto com código {codigoProduto}.")

  #Função para faturamento em reais baseado no cpf do cliente (simpledialog)
  def faturamentoCliente(self):
    cpfCliente = simpledialog.askstring("Faturamento por Cliente", "Digite o CPF do cliente:")
    faturamento = 0
    for cupom in self.listaCupons:
        if cupom.cpf == cpfCliente:
            for _, _, valorTotal in cupom.itensCupom:
                faturamento += valorTotal
    messagebox.showinfo("Faturamento por Cliente", f"Faturamento do cliente {cpfCliente}: R$ {faturamento:.2f}")

  #Função de faturamento referente às datas inicial e final 
  def faturamentoPeriodo(self):
    dataInicioStr = simpledialog.askstring("Faturamento por Período", "Digite a data inicial (dd/mm/aaaa):")
    dataFimStr = simpledialog.askstring("Faturamento por Período", "Digite a data final (dd/mm/aaaa):")
    dataInicio = datetime.strptime(dataInicioStr, '%d/%m/%Y')
    dataFim = datetime.strptime(dataFimStr, '%d/%m/%Y')
    faturamento = 0
    for cupom in self.listaCupons:
        if dataInicio <= cupom.data_emissao <= dataFim:
            for _, _, valorTotal in cupom.itensCupom:
                faturamento += valorTotal
    messagebox.showinfo("Faturamento por Período", f"Faturamento de {dataInicioStr} até {dataFimStr}: R$ {faturamento:.2f}")

  #Função que retorna quando vendeu para tal cliente com base no cpf e dentro do intervalo da data inicial e final
  def consultaVendasCliente(self):
    cpfCliente = simpledialog.askstring("Consulta Vendas", "Digite o CPF do cliente:")
    dataInicioStr = simpledialog.askstring("Consulta Vendas", "Digite a data inicial (dd/mm/aaaa):")
    dataFimStr = simpledialog.askstring("Consulta Vendas", "Digite a data final (dd/mm/aaaa):")
    
    dataInicio = datetime.strptime(dataInicioStr, '%d/%m/%Y')
    dataFim = datetime.strptime(dataFimStr, '%d/%m/%Y')

    notasFiscais = []
    for cupom in self.listaCupons:
        if cupom.cpf == cpfCliente and dataInicio <= cupom.data_emissao <= dataFim:
            valorNota = sum(valor for _, _, valor in cupom.itensCupom)
            # Formatação da string para cada nota fiscal
            notasFiscais.append(f"Número da Nota: {cupom.nroCupom}, Valor Total: R$ {valorNota:.2f}")

    if notasFiscais:
        notasStr = "\n".join(notasFiscais)
        messagebox.showinfo("Vendas para o Cliente", f"Notas Fiscais para o CPF {cpfCliente}:\n{notasStr}")
    else:
        messagebox.showinfo("Vendas para o Cliente", "Nenhuma venda encontrada para este CPF no período especificado.")

  #Função que organiza em um ranking de 5 posições produtos baseados em seu faturamento total em reais
  def produtosMaisVendidos(self):
    vendaProdutos = {}
    for cupom in self.listaCupons:
      for produto, qtd, valorTotal in cupom.itensCupom:
        if produto.codigo not in vendaProdutos:
          vendaProdutos[produto.codigo] = {'desc': produto.desc, 'valorUni': produto.valorUni, 'qtdVendida': 0, 'valorTotal': 0}
        vendaProdutos[produto.codigo]['qtdVendida'] += qtd
        vendaProdutos[produto.codigo]['valorTotal'] += valorTotal

    topVendidos = sorted(vendaProdutos.items(), key=lambda item: item[1]['valorTotal'], reverse=True)[:5]

    resultado = "Top 5 Produtos Mais Vendidos:\n"
    for codigo, dados in topVendidos:
      resultado += f"Código: {codigo}, Descrição: {dados['desc']}, Preço/Kg: R$ {dados['valorUni']}, Qtd Vendida: {dados['qtdVendida']} Kg, Valor Total: R$ {dados['valorTotal']:.2f}\n"

    messagebox.showinfo("Produtos Mais Vendidos", resultado)