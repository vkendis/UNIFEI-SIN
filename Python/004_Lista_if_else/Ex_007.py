"""
7) Cada estado da região sudeste possui uma taxa de imposto distinta sobre o valor dos produtos nele
comercializados. Faça um programa que leia o preço de um produto e o estado (use 1 = MG; 2 = SP; 3 = RJ;
e 4 = ES), e mostre o preço final acrescido do imposto, de acordo com as seguintes taxas: MG = 12%; SP =
7%; RJ = 15%; ES = 8%.
"""
valor = float(input("Digite o valor do produto: "))
estado = int(input("Digite o numero do estado de 1 a 4: \n1 = MG\n2 = SP\n3 = RJ\n4 = ES\n"))

if estado == 1:
    valor = valor*1.12
    print("O valor do produto sera recalculado com o imposto estadual e sera igual a: {:.2f} reais".format(valor))
elif estado == 2:
    valor = valor*1.07
    print("O valor do produto sera recalculado com o imposto estadual e sera igual a: {:.2f} reais".format(valor))
elif estado == 3: 
    valor = valor*1.15
    print("O valor do produto sera recalculado com o imposto estadual e sera igual a: {:.2f} reais".format(valor))
elif estado == 4:
    valor = valor*1.08
else: 
    print("Valor invalido")
    
