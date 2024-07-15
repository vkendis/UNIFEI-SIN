# Vinícius Kendi Sasaki - 2023013498
# Laviny Rodrigues Laurindo - 2023012893

import csv

# Como vimos em aula, usamos a árvore de busca Red-Black para equilibrar o conjunto de dados,
# tornando a busca mais eficiente e permitindo que o programa rode em menos de 1 segundo.

# O conjunto de dados alvo é um CSV que contém 1000 registros com 16 atributos.
# Devemos retornar a altura média da árvore após as operações de equilíbrio.

# Considerações: Para um conjunto de 1000 dados, temos log2(1000) = 10, assim podemos provar com a saída = 10 que a árvore para esse
# conjunto de dados está bem equilibrada.

#Referencias: https://www.programiz.com/dsa/red-black-tree

class No:
    # Define a estrutura de cada nó da árvore
    def __init__(self, pergunta=None, dados=None):
        self.pergunta = pergunta  
        self.dados = dados     
        self.esquerda = None      
        self.direita = None       
        self.cor = True           

def ehVermelho(no):
    # Verifica se o nó é vermelho
    return no is not None and no.cor

def rotacionarEsquerda(no):
    # Realiza rotação à esquerda para manter o equilíbrio da árvore
    direito = no.direita
    no.direita = direito.esquerda
    direito.esquerda = no
    direito.cor = no.cor
    no.cor = True
    return direito

def rotacionarDireita(no):
    # Realiza rotação à direita para manter o equilíbrio da árvore
    esquerdo = no.esquerda
    no.esquerda = esquerdo.direita
    esquerdo.direita = no
    esquerdo.cor = no.cor
    no.cor = True
    return esquerdo

def inverterCores(no):
    # Reajusta as cores após inserção para evitar dois nós vermelhos consecutivos
    no.cor = True
    no.esquerda.cor = False
    no.direita.cor = False

def inserirAux(raiz, pergunta, dados):
    # Insere um nó na árvore recursivamente
    if raiz is None:
        return No(pergunta, dados)
    
    if dados < raiz.dados:
        raiz.esquerda = inserirAux(raiz.esquerda, pergunta, dados)
    elif dados > raiz.dados:
        raiz.direita = inserirAux(raiz.direita, pergunta, dados)
    else:
        return raiz  # Nó já existe

    # Após a inserção, verifica a necessidade de rotações e ajustes de cores
    if ehVermelho(raiz.direita) and not ehVermelho(raiz.esquerda):
        raiz = rotacionarEsquerda(raiz)
    if ehVermelho(raiz.esquerda) and ehVermelho(raiz.esquerda.esquerda):
        raiz = rotacionarDireita(raiz)
    if ehVermelho(raiz.esquerda) and ehVermelho(raiz.direita):
        inverterCores(raiz)
    return raiz

def inserir(raiz, pergunta, dados):
    # Inicia  inserção e garante que a raiz seja negra
    raiz = inserirAux(raiz, pergunta, dados)
    raiz.cor = False
    return raiz

def lerCSV(arquivo):
    # Read no dataset
    with open(arquivo, newline='', encoding='utf-8') as csvfile:
        leitor = csv.reader(csvfile)
        cabecalho = next(leitor)
        dados = [linha for linha in leitor]
    return cabecalho, dados

def escolherPergunta(dados, perguntas):
    # Escolhe a pergunta que melhor balanceia as respostas sim e não
    melhorPergunta = None
    menorDiferenca = float('inf')
    for indice, pergunta in enumerate(perguntas):
        sim = sum(1 for d in dados if int(d[indice + 1]) == 1)
        nao = len(dados) - sim
        diferenca = abs(sim - nao)
        if diferenca < menorDiferenca:
            menorDiferenca = diferenca
            melhorPergunta = pergunta
    return melhorPergunta

def construirArvore(dados, perguntas):
    # Constrói a árvore binária baseada nas perguntas para dividir os dados
    if len(dados) == 1:
        return No(dados=dados[0])
    pergunta = escolherPergunta(dados, perguntas)
    dadosSim = [d for d in dados if d[perguntas.index(pergunta) + 1] == '1']
    dadosNao = [d for d in dados if d[perguntas.index(pergunta) + 1] == '0']
    raiz = No(pergunta=pergunta)
    raiz.esquerda = construirArvore(dadosSim, perguntas)
    raiz.direita = construirArvore(dadosNao, perguntas)
    return raiz

def calcularAlturas(raiz, alturaAtual=0):
    # Calcula a altura de cada folha da árvore e conta quantas folhas existem
    if not raiz:
        return [], 0
    if not raiz.esquerda and not raiz.direita:
        return [alturaAtual], 1  # Retorna uma lista com as alturas e a contagem de folhas
    alturasEsq, contEsq = calcularAlturas(raiz.esquerda, alturaAtual + 1)
    alturasDir, contDir = calcularAlturas(raiz.direita, alturaAtual + 1)
    return alturasEsq + alturasDir, contEsq + contDir


input_csv = input() # Alterado para receber qualquer csv como entrada
cabecalho, dados = lerCSV(input_csv)
perguntas = cabecalho[1:]  #ignora header

arvore = construirArvore(dados, perguntas)

alturas, totalFolhas = calcularAlturas(arvore)
alturaMedia = sum(alturas) / totalFolhas if totalFolhas else 0
print(f"{alturaMedia:.2f}")