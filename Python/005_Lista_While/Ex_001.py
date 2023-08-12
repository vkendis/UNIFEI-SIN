"""
1) Faça um programa que leia um inteiro N e implemente um contador regressivo, para imprimir na tela os 
números de N até 1. Imprima os números em uma única linha, separados entre si por um único espaço.
"""

n1 = int(input("Digite o numero para n1: "))
aux = n1
#Metodo 1: 
print("Print do primeiro metodo: ")
while n1 >= 1:
    print(n1, end=" ")
    n1-=1

print("\n")

#Metodo 2:

print("Print do segundo metodo: ")
for aux in range(aux,0,-1):
    
    print(aux, end=" ")
