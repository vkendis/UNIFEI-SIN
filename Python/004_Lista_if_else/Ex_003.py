"""
3) Faça um programa que leia um valor inteiro e, caso este valor seja positivo, calcule e mostre a sua raiz
quadrada. Caso ele seja negativo, calcule e mostre o seu quadrado.
"""
import math
n1 = int(input("Digite um numero: "))

if n1 > 0:
    resultado = math.sqrt(n1)
    print(resultado)
else:
    resultado = n1**2
    print(resultado)