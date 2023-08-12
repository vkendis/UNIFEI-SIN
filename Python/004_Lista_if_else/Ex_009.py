"""
9) Faça um programa que determine se um determinado ano lido é bissexto. Um ano é bissexto se for
divisível por 400, ou se for divisível por 4 e não for divisível por 100. Seu programa deve imprimir apenas
as respostas “sim” ou “nao”.
"""

ano = int(input("Digite o ano: "))

if ano % 400 == 0 or ano % 4 == 0 and ano % 100 != 0:
    print("Sim")
else: 
    print("Nao")

          