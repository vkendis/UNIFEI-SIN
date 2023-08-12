"""
2)  Faça  um  programa  que  leia  um  inteiro  positivo  N  e  imprima  todos  os  números  naturais  de  0  até  N,  em 
ordem  crescente.  Imprima  os  números  em  uma  única  linha,  separados  entre  si  por  um  único  espaço.  Não 
deixe o usuário inserir um valor negativo. Se um valor negativo for inserido, continue lendo N. 
"""

#Metodo 1: 
while True:
    n1 = int(input("Digite um número para n1: "))
    if n1 > 0:
        break
aux = n1
for n1 in range(0,n1+1,1):  
    print(n1, end=" ")

print("\n\n")
#Metodo 2: 

n1 = int(input("Digite um novo valor para n1: "))
while n1 <= 0:
    n1 = int(input("Digite um novo valor para n1: "))-5
    
    print(n1, end=" ")