"""
3) Faça um programa que leia um inteiro N e mostre quais são os N primeiros números ímpares. Imprima os 
números em uma única linha, separados entre si por um único espaço. Atenção: se o usuário digita N = 4, a 
resposta é: 1 3 5 7 (que são os 4 primeiros números ímpares!). 
"""
print("Print do metodo 1: ")
#Metodo 1: 
while True:
    n = int(input("Digite um numero para n: "))
    if n > 0:
        break
aux = n
for n in range(1, 2*n, 2):
    print(n, end=" ")

print("\n")

#Metodo 2: 
print("Print do metodo 2: ")
i = 0
impar = 1
while i < aux:
    print(impar, end=" ")
    impar += 2
    i+=1