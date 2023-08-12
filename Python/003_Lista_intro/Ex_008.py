"""
8) O volume de um cilindro é dado pela seguinte fórmula: V = πr2h, onde r é o valor raio, h é a sua altura e π 
é uma constante matemática. Faça um programa que leia os valores de r e h e calcule o volume do cilindro 
correspondente, com duas casas decimais. Represente π com todas as suas casas decimais. 
"""
raio = float(input("Digite o valor do raio: "))
altura = float(input("Digite o valor do altura: "))

volume = 3.14 * raio**2 * altura

print("O volume do cilindo sera igual a: {:.2f}".format(volume))