"""
7) Fazer um algoritmo para resolver uma equação do primeiro grau.
"""
import math
import numpy as np #biblioteca para fazer direto equacao de segundo grau
print("Digite os valores para: a, b e c")

a = float(input())
b = float(input())
c = float(input())

raizes = np.roots([a, b, c])
print("As raizes da equacao sao:", raizes)