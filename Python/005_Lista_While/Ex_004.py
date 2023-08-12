"""
4)  Faça  um  programa  que  leia  um  inteiro  positivo  N,  calcule  e  mostre  a  soma  dos  N  primeiros  números 
ímpares. Não deixe o usuário inserir um valor negativo. Se um valor negativo for inserido, continue lendo N.
"""
soma = 0  # Inicializa a variável soma

while True:
    n = int(input("Digite um número para N: "))
    if n > 0:
        break

for num in range(1, 2*n+1, 2):
    soma += num  # Acumula os números ímpares na variável soma

print("A soma dos primeiros", n, "números ímpares é:", soma)
