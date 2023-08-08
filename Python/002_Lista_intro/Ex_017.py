"""
17)  Fazer  um  programa  que  receba  três  números  e  mostre  como  resposta  o  quadrado  da  soma  desses 
números.
"""
print("Digite os 3 numeros: ")

n1 = int(input())
n2 = int(input())
n3 = int(input())

#Metodo 1:

somatorio = (n1+n2+n3)**2
print("O somatorio do metodo 1 sera igual a: ", somatorio)

#Metodo 2: 

numeros = [n1+n2+n3]
somatoriolista = sum(numeros)
print("O somatorio dos numeros sera igual a:", somatoriolista**2)