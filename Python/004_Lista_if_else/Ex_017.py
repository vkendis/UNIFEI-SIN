"""
17)  A  Copa  do  Mundo  de  2026  será  realizada  na  América  do  Norte.  Bolas  de  futebol  são  muito  fáceis  de 
transportar, já que elas saem das fábricas vazias e são enchidas somente pelas lojas ou pelos consumidores 
finais. Infelizmente o mesmo não pode ser dito das bolas de boliche. Como elas são completamente sólidas, 
elas  só  podem  ser  transportadas  embaladas  uma  a  uma,  em caixas separadas.  A  SBI  (Só Boliches 
Internacional) é uma fábrica de bolas de boliche que trabalha somente através de encomendas e envia todas 
as  bolas  via  correios.  Como  as  bolas  têm  tamanhos  diferentes,  a  SBI  tem  vários  tamanhos  de  caixas 
diferentes para transportá-las. Escreva um programa que, dado o diâmetro de uma bola e as 3 dimensões de 
uma  caixa  (altura,  largura  e  profundidade),  informe  se  a  bola  de  boliche  cabe  dentro  da  caixa  ou  não.  Seu 
programa deve imprimir apenas as respostas “sim” ou “nao”.
"""
diametro = float(input("Digite o diametro da bola: "))
altura = float(input("Digite a altura da caixa: "))
largura = float(input("Digite a largura da caixa: "))
profundidade = float(input("Digite a profundidade da caixa: "))

if (diametro < altura) and (diametro < largura) and (altura <= profundidade):
    print("Sim")
else: 
    print("Nao")