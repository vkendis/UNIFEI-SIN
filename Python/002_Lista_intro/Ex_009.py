"""
9) Fazer um programa para converter uma dada temperatura de graus Celsius para graus Fahrenheit.
"""
# Solicita ao usuário para digitar a temperatura em Celsius
temperatura_celsius = float(input("Digite a temperatura em graus Celsius: "))

# Fórmula de conversão de Celsius para Fahrenheit: F = C * 9/5 + 32
temperatura_fahrenheit = temperatura_celsius * 9/5 + 32

# Imprime o resultado da conversão
print(f"{temperatura_celsius:.2f} graus Celsius equivalem a {temperatura_fahrenheit:.2f} graus Fahrenheit.")
