"""
8) Fazer um algoritmo para resolver uma equação do segundo grau. Seu algoritmo deve verificar se a equação é 
realmente de segundo grau e tratar o valor do discriminante delta adequadamente.
"""
import math

print("Digite os coeficientes da equação quadrática ax^2 + bx + c = 0:")
a = float(input("Digite o valor de 'a': "))
b = float(input("Digite o valor de 'b': "))
c = float(input("Digite o valor de 'c': "))

# Verifica se a equação é realmente de segundo grau
if a == 0:
    print("A equação não é de segundo grau.")
else:
    # Calcula o discriminante
    delta = b**2 - 4*a*c
    
    if delta > 0:
        # Duas raízes reais distintas
        x1 = (-b + math.sqrt(delta)) / (2*a)
        x2 = (-b - math.sqrt(delta)) / (2*a)
        print(f"As raízes são: x1 = {x1:.2f} e x2 = {x2:.2f}")
    elif delta == 0:
        # Uma raiz real (raiz dupla)
        x = -b / (2*a)
        print(f"A raiz dupla é: x = {x:.2f}")
    else:
        # Duas raízes complexas
        real_part = -b / (2*a)
        imaginary_part = math.sqrt(abs(delta)) / (2*a)
        print(f"As raízes complexas são: x1 = {real_part:.2f} + {imaginary_part:.2f}i e x2 = {real_part:.2f} - {imaginary_part:.2f}i")
