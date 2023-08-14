"""
1) Faça um programa que leia um vetor de char com 8 posições e, a seguir, mostre os valores lidos em
ordem inversa.
"""
vetor = []

for i in range(8):
    char = input(f"Digite o caractere{i+1}: ")
    vetor.append(char)

print("Valores em ordem inversa: ")
for i in range (7, -1, -1):
    print(vetor[i], end= " ")