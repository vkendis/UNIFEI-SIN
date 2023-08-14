"""
10)  Faça  um  programa  que  leia  um  inteiro  positivo  N  e  mostre  a  soma  de  seus  divisores.  Por  exemplo,  a 
soma  dos  divisores  de  30  é  1  +  2  +  3  +  5  +  6  +  10  +  15  +  30  =  72.  Não  deixe  o  usuário  inserir  um  valor 
negativo.
"""
soma = 0
n1 = int(input("Digite um numero para n1: "))

for num in range(n1, 0, -1):
    if n1 % num == 0:
        soma += num 
print(soma)    