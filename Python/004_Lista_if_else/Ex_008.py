"""
8) Faça um programa que leia um valor inteiro e informe se o valor lido é ou não é um múltiplo de 11. Seu
programa deve imprimir apenas as respostas “sim” ou “nao”.
"""
n1 = int(input("Digite um numero: "))

if n1 % 11 == 0:
    print("Sim")
else:
    print("Nao")