"""
15) Faça um programa que verifique se um número lido é divisível por 3 ou por 5, mas não pelos dois ao
mesmo tempo. Imprima como resposta apenas as frases: “divisivel por 3”, “divisivel por 5”,
“nao divisivel”, de acordo com a entrada recebida.
"""
n1 = int(input("Digite o valor para n1: "))

if n1 % 3 == 0 and n1 % 5 == 0:
    print("Nao Divisivel\n")
elif n1 % 3 == 0 and n1 % 5 != 0:
    print("Divisivel por 3")
elif n1 % 5 == 0 and n1 % 3 != 0:
    print("Divisivel por 5")
else:
    print("Valor nao divisivel")