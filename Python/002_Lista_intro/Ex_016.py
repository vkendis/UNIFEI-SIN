"""
16)  Fazer  um  programa  que  receba  três  números  e  mostre  como  resposta  a  soma  dos  quadrados  desses 
números.
"""
print("Digite os 3 numeros: ")

n1 = int(input())
n2 = int(input())
n3 = int(input())

#Metodo 1: 

somatorio = n1**2+ n2**2 + n3**2
print("O somatorio sera igual a: ", somatorio)

#Metodo 2: Conversao dos numeros para seus respectivos quadrados e depois funcao sum. 

n1q = n1**2
n2q = n2**2
n3q = n3**2

numeros = [n1q, n2q, n3q]
somatoriolista = sum(numeros)

print("O somatorio do metodo 2 sera igual a: ", somatoriolista)
