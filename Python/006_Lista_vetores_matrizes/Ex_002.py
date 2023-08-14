"""
2) Faça um programa que declare e leia um vetor com 10 números reais. Calcule e armazene em um segundo
vetor o quadrado de cada número real lido. Mostre os dois vetores na tela. Imprima cada vetor em uma linha,
com os números separados entre si por um único espaço.
"""
v1 = []

for i in range(10):
    reais = float(input(f"Digite o valor de numero {i+1}: "))
    v1.append(reais)

v2 = []  # Cria um segundo vetor para armazenar os quadrados

for num in v1:
    quadrado = num ** 2
    v2.append(quadrado)

for i in range(10):
    print(v1[i], v2[i])  # Imprime os valores dos dois vetores lado a lado
