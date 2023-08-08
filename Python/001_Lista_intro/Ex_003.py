"""
3)  Fazer  um  algoritmo  para  converter  uma  temperatura  de  graus  Celsius  para  graus  Fahrenheit.  A  fórmula  de 
conversão é: F = C * (9 / 5) + 32
"""

print("Digite a temperatura em graus celsius\n")
temp = float(input())

fah= temp*(9/5) + 32
print("A conversao de graus celsius sera igual a: {:.2f} graus Fahrenheit".format(fah))