"""
5) Faça um programa que leia duas notas de um aluno e verifique se estas notas são válidas. Uma nota é
válida se ela está no intervalo de 0 a 10. Caso as notas sejam válidas, mostre a média entre elas. Caso não
sejam válidas, mostre a mensagem “notas incorretas”.
"""
while True:
    n1 = float(input("Digite a         nota 1 do aluno: "))
    if 0 <= n1 <= 10:
        break
    else: 
        print("Digite o numero novamente")
while True:
    n2 = float(input("Digite a         nota 2 do aluno: "))
    if 0 <= n2 <= 10:
        break
    else: 
        print("Digite o numero novamente")

media = (n1 + n2)/2
print("A media do aluno sera igual a {:.2f}".format(media))