"""
4) Um grupo de amigos pretende alugar um carro por um certo número de dias. Consultadas duas agências, a 
primeira cobra R$ 62,00 pela diária  e mais R$ 1,40 por km rodado. A segunda agência cobra diária de R$ 
80,00 e mais R$ 1,20 por km rodado. Escreva um programa que leia a quantidade de km a serem percorridos 
e  a  quantidade  de  dias  de  aluguel  do  carro.  A  seguir,  mostre,  como  resposta,  uma  única  linha  contendo  o 
valor cobrado pela primeira agência separado do valor cobrado pela segunda agência por um único espaço.
"""

print("Digite a quantidade em (km) e a quantidade de dias de aluguel:")
distancia = float(input())
dias = int(input())

valor_ag1 = (dias*62) + (1.40*distancia)
valor_ag2 = (dias*80) + (1.20*distancia)

print("O valor da agencia 1 e igual a: {} reais, e o valor da agencia 2 e igual a: {} reais".format(valor_ag1,valor_ag2))