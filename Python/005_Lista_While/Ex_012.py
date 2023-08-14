"""
12)  Faça  um  programa  que  leia  um  número  N  e  mostre  a  soma  dos  N  primeiros  termos  da  seguinte 
expressão: S = 1 – 2 + 3 – 4 + 5 – 6 + ... + N.
"""
n1 = int(input("Digite um numero para n1: "))

sinal = 1
soma = 0
for num in range(1, n1+1, 1):
    soma += sinal*num
    sinal*= -1
print(soma)