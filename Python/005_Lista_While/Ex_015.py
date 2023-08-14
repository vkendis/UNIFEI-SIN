"""
15)  Faça  um  programa  que  leia  um  número  N  e  mostre  a  soma  dos  N  primeiros  termos  da  seguinte 
expressão, com precisão de duas casas decimais: S = + 1/1 + 3/2 – 5/3 – 7/4 + 9/5 + 11/6 – 13/7 – 15/8 + ...
"""
n = int(input("Digite um numero para n: "))
soma = 0 
sinal = 1
numerador = 1
denominador = 1
contasinal = 0
for num in range(1, n+1, 1):
    soma += sinal * (numerador/denominador)
    numerador += 2
    denominador += 1
    contasinal += 1
    if contasinal == 2:
        sinal *= -1
        contasinal = 0
print("{:.2f}".format(soma))
