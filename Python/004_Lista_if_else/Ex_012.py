"""
12) Faça um programa que leia as medidas dos 3 lados de um triângulo e mostre o tipo de triângulo:
equilátero, isósceles ou escaleno. Imprima apenas o nome do triângulo, em letras minúsculas e sem acentos.
"""

a = int(input("Digite o tamanho do lado A: "))
b = int(input("Digite o tamanho do lado B: "))
c = int(input("Digite o tamanho do lado C: "))

if a == b == c:
    print("Equilatero")
elif (a == b and a != c) or ( a == c and a!= b) or (b == c and b != a):
    print("Isosceles")
else: 
    print("Escaleno")