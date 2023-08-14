"""
13)  Faça  um  programa  que  leia  um  número  N  e  mostre  a  soma  dos  N  primeiros  termos  da  seguinte 
expressão, com precisão de duas casas decimais: S = – 1 + 1/2 – 1/3 + 1/4 – 1/5 + ... + 1/N.
"""

n = int(input("Digite um numero para n: "))

soma = 0
sinal = -1
for num in range(1, n+1, 1):
    soma += sinal*(1/num)
    sinal *= -1
print(soma)