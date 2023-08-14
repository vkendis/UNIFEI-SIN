"""
14)  Faça  um  programa  que  leia  um  número  N  e  mostre  a  soma  dos  N  primeiros  termos  da  seguinte 
expressão, com precisão de duas casas decimais: S = 0/1 + 2/2 + 4/4 + 6/8 + 8/16 + 10/32 + 12/64 + 14/128 
+ ...
"""
n = int(input("Digite um numero para n: "))

soma = 0 
numerador = 0
for num in range(1, n+1, 1):
    soma += (numerador/2 ** num)
    numerador +=2
print(soma)