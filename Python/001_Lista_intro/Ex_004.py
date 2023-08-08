"""
4) Fazer um algoritmo para converter um ângulo de graus para radianos. A fórmula de conversão é: rad = graus 
* π / 180, onde π = 3.14.
"""
print("Digite o angulo em graus: \n")
angulo = float(input())

pi=3.14

rad = (angulo*pi)/180
print("A conversao do angulo em radianos sera igual a: {:.2f}".format(rad))