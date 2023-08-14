"""
9) Faça um programa que leia uma quantidade desconhecida de valores inteiros e mostre a sua média, com 1 
casa decimal. O programa deve parar de ler quando um valor negativo for inserido. 
"""

#Metodo : Enquanto for verdade, le um valor para n, se n for negativo --> break
# soma recebe n e i recebe 1
#Saindo do loop, se i for maior que zero, printa a media
soma = 0
i = 0
while True: 
    n = int(input("Digite um valor para n: "))
    if n < 0:
        break 

    soma += n
    i += 1

if i > 0:
    media = soma/i
    print(media)
else: 
    print("Nenhum valor inserido")

