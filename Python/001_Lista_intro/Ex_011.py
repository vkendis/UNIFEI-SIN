"""
11) Fazer um algoritmo que receba três números como entrada e mostre qual o menor deles.
"""
print("Digite 3 numeros: ")

n1 = int(input())
n2 = int(input())
n3 = int(input())

#Metodo 1: Comparacao entre as variaveis e print do menor numero

if n1 < n2 and n1 < n3:
    print("O menor número é:", n1)
elif n2 < n1 and n2 < n3:
    print("O menor número é:", n2)
else:
    print("O menor número é:", n3)

#Metodo 2: Ordenacao da lista e printar o indice 0

notas = [n1,n2,n3]
notas_ordenadas = sorted(notas)
menor_numero = notas_ordenadas[0]
print("O menor numero e: ",menor_numero)
