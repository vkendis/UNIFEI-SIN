"""
6) Faça um programa que leia dois inteiros A e B, calcule e mostre: a soma dos números pares no intervalo 
[A, B] e o produto dos números ímpares no intervalo [A, B]. Imprima as duas respostas em uma única linha, 
separadas entre si por um único espaço. 
"""
n1 = int(input("Digite um numero para n1: "))
n2 = int(input("Digite um numero para n2: "))

for num in range(n1,n2+1,1):
    if num % 2 == 0:
        print(num, end=" ")