"""
10) Faça um programa que resolva uma equação de segundo grau, na forma: ax2 + bx + c = 0. Caso a
equação possua duas raízes, imprima-as em uma mesma linha, sendo a raiz de menor valor impressa
primeiro e separada da maior raiz por um único espaço. Se a equação possuir apenas uma raiz, imprima
somente este valor. Caso a equação não possua raízes reais, imprima a mensagem “sem raizes reais”.
"""

import math

def solve_quadratic_equation(a, b, c):
    discriminant = b**2 - 4*a*c
    
    if discriminant > 0:
        root1 = (-b + math.sqrt(discriminant)) / (2*a)
        root2 = (-b - math.sqrt(discriminant)) / (2*a)
        print(f"Raízes: {min(root1, root2)} {max(root1, root2)}")
    elif discriminant == 0:
        root = -b / (2*a)
        print(f"Raiz única: {root}")
    else:
        print("Sem raízes reais")

# Solicita os coeficientes ao usuário
a = float(input("Digite o coeficiente a: "))
b = float(input("Digite o coeficiente b: "))
c = float(input("Digite o coeficiente c: "))

# Chama a função para resolver a equação
solve_quadratic_equation(a, b, c)


