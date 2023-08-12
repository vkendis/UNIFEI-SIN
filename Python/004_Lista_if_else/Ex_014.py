"""
14) Faça um programa que receba a altura (valor real) e o sexo (m ou f) de uma pessoa e calcule e mostre
seu peso ideal, utilizando as seguintes fórmulas (onde h corresponde à altura):
• Homens: (72,7 * h) – 58
• Mulheres: (62,1 * h) – 44,7
"""
altura = float(input("Digite a altura do usuario: \n"))
sexo = str(input("M ou F\n"))

if sexo == 'm':
    Peso = (72.7*altura)-58
    print("O peso ideal do usuario sera igual a: {:.2f}".format(Peso))
elif sexo == 'f':
    Peso = (62.1*altura)-44.7
    print("O peso ideal do usuario sera igual a: {:.2f}".format(Peso))
else: 
    print("Entrada invalida")
    