"""
2) Faça um programa que receba quatro números e mostre qual deles é o menor.
"""
n1 = int(input())
n2 = int(input())
n3 = int(input())
n4 = int(input())

numeros = [n1,n2,n3,n4]
numeros_ord = sorted(numeros)
print(numeros[0])
