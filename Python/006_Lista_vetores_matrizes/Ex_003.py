"""
3) Faça um programa que declare e leia um vetor com 8 posições. A seguir, leia dois valores X e Y que
corresponderão a duas posições do vetor. Ao final, mostre a soma dos elementos presentes nas posições X e
Y. Seu programa não deve permitir que o usuário informe valores inválidos para X e Y.
"""

vetor = []
soma = 0

# Lê os valores para o vetor
for i in range(8):
    valor = float(input(f"Digite o numero {i + 1}: "))
    vetor.append(valor)

# Lê os valores para x e y e verifica se são válidos
while True:
    x = int(input("Digite um numero para x (entre 0 e 7): "))
    y = int(input("Digite um numero para y (entre 0 e 7): "))
    
    if 0 <= x < 8 and 0 <= y < 8:
        soma = vetor[x] + vetor[y]
        print(f"A soma dos elementos nas posições {x} e {y} é: {soma}")
        break  # Sai do loop se as entradas forem válidas
    else:
        print("Valores de x e/ou y inválidos. Por favor, tente novamente.")
