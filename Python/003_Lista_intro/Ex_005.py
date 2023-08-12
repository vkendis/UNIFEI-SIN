"""
5) Faça um programa que leia um número inteiro e mostre,  como resposta, a soma de sua  raiz  cúbica com 
sua raiz quarta. Mostre o resultado usando duas casas decimais.
"""
import math
n1 = int(input("Digite um numero: "))

r3 = math.pow(n1, 1/3)
r4 = math.pow(n1, 1/4)

resultado = r3+r4
print("A soma das raizes e igual a: {:.2f}".format(resultado))