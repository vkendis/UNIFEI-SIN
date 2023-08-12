"""
7)  Faça  um  programa  que  leia  o  valor  de  ângulo,  dado  em  graus,  e  mostre,  com  duas  casas  decimais,  os 
valores de seno, cosseno e tangente do ângulo lido, em uma única linha, separados por um único espaço.
"""
import math

angulo = float(input("Digite o valor do angulo: "))

#A funcao math trabalha com os angulos em radianos, por isso deve-se transformar em radianos para operar.

seno = math.sin(math.radians(angulo))
cosseno = math.cos(math.radians(angulo))
tangente = math.tan(math.radians(angulo))

print(" {:.2f} {:.2f} {:.2f}".format(seno,cosseno,tangente))