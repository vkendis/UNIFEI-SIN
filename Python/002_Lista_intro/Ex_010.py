"""
10) Fazer um programa para converter uma dada temperatura de graus Fahrenheit para graus Celsius.
"""
# Solicita ao usuário para digitar a temperatura em Fahrenheit
temperatura_fahrenheit = float(input("Digite a temperatura em graus Fahrenheit: "))

# Fórmula de conversão de Fahrenheit para Celsius: C = (F - 32) * 5/9
temperatura_celsius = (temperatura_fahrenheit - 32) * 5/9

# Imprime o resultado da conversão
print(f"{temperatura_fahrenheit:.2f} graus Fahrenheit equivalem a {temperatura_celsius:.2f} graus Celsius.")
