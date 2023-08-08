"""
3)  Fazer  um  programa  que  receba  três  valores,  que  podem  ser  inteiros  ou  reais,  e  mostre  a  soma  desses 
"""
print("Digite 3 numeros: ")

n1 = float(input())
n2 = float(input())
n3 = float(input())

soma = n1+n2+n3
print("A soma do primeiro metodo sera igual a:",soma)

# Metodo 2: Colocar numeros na lista e depois printar a soma 

numeros = [n1,n2,n3]

somadosnumeros = sum(numeros)
print("A soma do segundo metodo sera igual a:", somadosnumeros)