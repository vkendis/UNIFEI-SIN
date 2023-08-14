"""
7) Faça um programa que leia um inteiro positivo N e mostre quais são os seus divisores. Por exemplo, os 
divisores  de  30  são  1,  2,  3,  5,  6,  10,  15  e  30.  Não  deixe  o  usuário  inserir  um  valor  negativo.  Imprima  os 
números em uma única linha, separados entre si por um único espaço.
"""
n1 = int(input("Digite um numero para n1: 1"))

for num in range(n1, 0, -1):
    if n1 % num == 0:
        print(num, end=" ")
