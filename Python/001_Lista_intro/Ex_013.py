"""
13)  Fazer  um  algoritmo  que  receba  um  número  representando  a  temperatura  corporal  de  um  paciente.  Caso  o 
valor  seja  maior  que  39,  mostre  a  mensagem  “Febre  alta”.  Caso  o  valor  esteja  entre  38  e  39,  mostre  a 
mensagem “Febre baixa”. Caso contrário, mostre a mensagem “Temperatura Normal”. 
"""
print("Digite a temperatura: ")

temp = float(input())

if temp > 39:
    print("Febre alta")
elif temp >= 38 and temp <=39:
    print("Febre baixa")
else:
    print("Temperatura normal")