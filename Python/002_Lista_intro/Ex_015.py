"""
15) Fazer um programa que leia a distância (km) percorrida por um veículo e o tempo gasto (h), mostrando 
como resposta a sua velocidade média: Vm = delta s /  delta t.
"""
print("Digite a distancia em (km) e o tempo gasto em (h): ")

distancia = float(input())
tempo = float(input())

velocidade_media = distancia/tempo
print("A velocidade media sera igual a: ", velocidade_media)