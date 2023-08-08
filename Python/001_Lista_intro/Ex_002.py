"""
2) Fazer um algoritmo para calcular a área de um círculo. Sabe-se que a área do círculo é dada pelo produto do 
raio ao quadrado pela constante π = 3.14. Nos fluxograma e pseudocódigo, represente π como 'pi'.
"""
print("Digite o raio do circulo: ")
raio = float(input())
pi = 3.14

area = raio**2*pi
print("A area do circulo sera igual a: {:.2f}".format(area))