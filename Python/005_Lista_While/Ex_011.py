"""
11) Faça um programa que leia um inteiro X e mostre a diferença entre o quadrado da soma pela soma dos 
quadrados dos X primeiros números naturais. 
Exemplo: seja X = 10: 
Quadrado da soma: (1 + 2 + ... + 10)2 = (55)2 = 3025 
Soma dos quadrados: (12 + 22 + ... + 102) = 385 
Diferença: 3025 – 385 = 2640
"""
soma = 0
quaddasoma = 0
somadosq = 0
x = int(input("Digite um valor para x: "))

for num in range(1, x + 1):
    soma += num
    quaddasoma += num ** 2

somadosq = soma ** 2
diferenca = somadosq - quaddasoma
print(diferenca)
