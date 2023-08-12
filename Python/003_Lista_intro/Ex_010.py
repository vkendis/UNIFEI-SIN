"""
10) Uma máquina demora 17 segundos para produzir uma peça. Faça um programa que leia a quantidade de 
peças que devem ser produzidas e mostre o tempo em horas, minutos e segundos necessários para produzir 
essa  quantidade  de  peças.  Por  exemplo,  se  um  operador  deseja  produzir  4  peças,  a  máquina  gastaria  68 
segundos.  Nesse  caso,  o  programa  daria  como  resposta:  0  horas,  1  minuto  e  8  segundos.  Em  sua  resposta, 
indique somente os números, separados por um único espaço entre eles. Por exemplo: 0 1 8. 
"""
npeca = int(input("Digite o número de peças que deseja produzir: "))

tempo_peca = 17  # Tempo em segundos para produzir uma peça

tempo_total_segundos = npeca * tempo_peca
horas = tempo_total_segundos // 3600
minutos = (tempo_total_segundos % 3600) // 60
segundos = tempo_total_segundos % 60

print(f"{horas} {minutos} {segundos}")
