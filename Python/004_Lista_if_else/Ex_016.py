"""
16) Uma empresa  aérea  quer contratar novos  comissários de vôo. Se a pessoa for homem, a altura mínima 
exigida  é  de  1,75m.  No  caso  das  mulheres,  é  necessário  ter  ao  menos  1,80m  de  altura.  Faça  um  programa 
que leia a altura (valor real) e o sexo (m ou f) de uma pessoa e informe se ela pode ou não ser contratada. 
Seu programa deve imprimir apenas as respostas “sim” ou “nao”.
"""
altura = float(input("Digite a altura do usuario: "))

sexo = input("Digite o sexo do usuario: ")

if (sexo == 'm' and altura >= 1.75) or (sexo == 'f' and altura >= 1.80):
    print("Sim")
else: 
    print("Nao")
