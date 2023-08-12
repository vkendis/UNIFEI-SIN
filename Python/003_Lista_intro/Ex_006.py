"""
6)  Uma  das  fórmulas  alternativas  para  se  calcular  a  área  de  um  triângulo  é  a  Fórmula  de  Herão,  que  dá  o 
valor da área em função da medida dos três lados do triângulo. A fórmula é dada por 
𝐴= √𝑝(𝑝−𝑎)(𝑝−𝑏)(𝑝−𝑐), onde a, b e c são  as medidas dos lados e  p é o  semiperímetro (metade do 
perímetro). Faça um programa que leia as medidas dos lados do triângulo e mostre o valor de sua área, com 
uma única casa decimal. 
"""

import math

a = int(input("Digite o valor para a: "))
b = int(input("Digite o valor para b: "))
c = int(input("Digite o valor para c: "))
p = (a+b+c)/2

area = math.sqrt(p*(p-a)*(p-b)*(p-c))
print("A area do triangulo sera igual a: {:.2f}".format(area))