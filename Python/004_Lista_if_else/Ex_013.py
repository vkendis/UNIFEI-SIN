"""
13) Faça um programa que leia a idade de um nadador e mostre em qual categoria ele é classificado, de
acordo com a tabela a seguir.
"""

idade = int(input("Digite a idade do usuario: "))

if 4 <= idade <= 5:
    print("Fraldinha")
elif 6 <= idade <= 12:
    print("Infantil")  
elif 13 <= idade <= 18:
    print("Juvenil")
else: 
    print("Adulto")