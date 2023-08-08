"""
2) Faça um programa para calcular o valor de desconto de um produto pago à vista. O programa deve ler o 
valor  do  produto  e  a  porcentagem  de  desconto  à  vista  (valor  inteiro).  Imprima,  como  resposta,  uma  única 
linha contendo o valor final do produto e o valor do desconto, separados entre si por um único espaço. 
"""

print("Digite o valor do produto e a porcentagem de desconto desejado: ")
valorinicial = float(input())
desconto = int(input())

porcentagem = 1-(desconto/100)
valorfinal = valorinicial*porcentagem
valordescontado = valorinicial - valorfinal
print("O valor final do produto foi de: {:.2f} reais e o valor descontado foi de: {:.2f} ".format(valorfinal,valordescontado))