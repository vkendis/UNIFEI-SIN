"""
8) Faça um programa que leia dois inteiros N e X e mostre a soma dos múltiplos de X menores que N. Não 
deixe o usuário inserir valores negativos.
"""

n = int(input("Digite um valor para n: "))
x = int(input("Digite um valor para x: "))
soma = 0

for num in range(1, n, 1):
    if num  %  x == 0:
        soma += num
print(soma)
