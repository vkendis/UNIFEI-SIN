"""
3)  A  bula  de  um  remédio  pediátrico  recomenda  a  seguinte  dosagem:  5  gotas  para  cada  2kg  de  peso  da 
criança. Faça um programa que leia o peso da criança e mostre a quantidade de gotas a ser ministrada.
"""
print("Digite a massa da crianca: ")
massa = float(input())

massadosagem = massa/2
dosagem = massadosagem*5

print("A dosagem ideal para a crianca sera igual a: {:.1f} gotas".format(dosagem))