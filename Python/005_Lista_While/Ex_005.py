"""
5)  Faça  um  programa  que  leia  dois  inteiros  N  e  X.  A  seguir,  mostre  quais  são  os  N  primeiros  números 
naturais que são múltiplos de X. Imprima os números em uma única linha, separados entre si por um único 
espaço.
"""
#Metodo 1: 
n = int(input("Digite o valor de n: "))
x = int(input("Digite o valor de x: "))

for num in range(1, n*x+1, 1):
    if num % x == 0:
        print(num, end=" ")
        
print("\n")

#Metodo 2: 
n = int(input("Digite o valor de n: "))
x = int(input("Digite o valor de x: "))
num = 1
cont = 0
while cont < n:
    if num % x == 0:
        print(num, end= " ")
        cont+=1
    num+=1
