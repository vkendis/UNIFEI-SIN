# Vinícius Kendi Sasaki - 2023013498
# Laviny Rodrigues Laurindo - 2023012893

# Neste trabalho 4, precisamos usar os conhecimentos da última aula de Algoritmos II sobre árvore B.
# A Árvore B basicamente é um algoritmos, o qual sempre cresce para cima.
# A inserção de um novo valor pode fazer com que as chaves atinjam o valor máx e assim forçem o valor mediano para a posição de nó pai.
# Assim há uma nova reorganização da árvore.

# O código abaixo implementa uma árvore B, com métodos para carregar dados de nós a partir de arquivos, 
# buscando manter a ordem das chaves e a correta distribuição entre os nós conforme novas inserções ocorrem.

#Referências: https://www.programiz.com/dsa/b-tree
#Referências: https://www.programiz.com/dsa/insertion-into-a-b-tree
#Link oferecido pelo Professor Pedro Hokama para estudarmos melhor o conceito e inserção deste algoritmo.

class noh:
    def __init__(self, fileName_="None"):
        # Todo noh corresponde a um arquivo no disco
        self.fileName = fileName_
        # A flag carregado indica se aquele noh já foi lido do disco
        self.carregado = False
        # Indica se o noh é folha
        self.folha = True
        # Lista das chaves e filhos ficam vazios até serem lidos do disco
        self.chaves = []
        self.filhos = []
        
    def carrega_arquivo(self, nome_arquivo):
        print("Lendo: ", nome_arquivo)
        self.carregado = True
        f = open(nome_arquivo, "r")
        for linha in f:
            linha = linha.strip() #método para tratar remoção de espaços
            if linha.endswith(".tree"): # Verifica se o arquivo termina com ".tree", se verdadeiro, executa o codigo dentro do bloco criando novos nós
                self.folha = False  # tem filho, não é folha
                self.filhos.append(noh(linha))  # cria um novo nó filho com o nome do arquivo
            else:
                try:
                    chave = int(linha)
                    self.chaves.append(chave)
                except ValueError:
                    # ignora
                    pass 
        f.close()  # fecha aquivo
        self.chaves.sort()
		
class arvoreB:
	def __init__(self, t, filename):
		self.t = t
		self.raiz = noh(filename)

	def busca(self, k, x):
		if x.carregado == False:
			#o nó existe mas não foi carregado
			x.carrega_arquivo(x.fileName)
		#procurando a chave ou o filho
		i = 0
		while i < len(x.chaves) and k > x.chaves[i]:
			i += 1
		
		if i < len(x.chaves) and k == x.chaves[i]:
			#encontrei a chave
			return (x, i)
		elif x.folha:
			#a chave k estaria no filho, mas x jah eh folha
			return None
		else:
			#a chave k esta no filho i
			return self.busca(k, x.filhos[i])
		


B = arvoreB(2, "0.tree")
i = int(input())
while(i != -1):
	if(B.busca(i, B.raiz) == None):
		print(str(i) + " nao encontrado")
	else:
		print(str(i) + " encontrado")
	i = int(input())
	
	
