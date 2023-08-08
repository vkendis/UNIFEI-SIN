"""
12) Fazer um algoritmo que receba um número representando a temperatura da  água  e mostre em qual estado 
físico (sólido, líquido ou gasoso) ela se encontra. 
"""

print("Digite a temperatura atual da agua: ")

temp = float(input())

if temp < 0:
    print("A agua esta no estado solido")
elif temp == 0:
    print("A agua possui estado solido e liquido ao mesmo tempo")
elif temp > 0 and temp <100:
    print("A agua esta em estado liquido")
elif temp == 100:
    print("A agua possui estado liquido e gasoso ao mesmo tempo")
else:
    print("A agua esta no estado gasoso")