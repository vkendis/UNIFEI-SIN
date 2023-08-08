"""
13) Fazer um programa que receba o ano de nascimento de uma pessoa e o ano atual. A seguir, o algoritmo 
deve calcular e mostrar: a) a idade da pessoa em anos. b) a idade da pessoa em meses. c) a idade da pessoa 
em dias.
"""
print("Digite o ano atual e o ano de nascimento: ")

anoatual=int(input())
anonas=int(input())

ano = anoatual-anonas
print("A sua idade sera igual a: ", ano)

ano_em_meses = ano*12
print("A idade em meses sera igual a:", ano_em_meses)

ano_em_dias = ano*365
print("A idade em dias sera igual a: ", ano_em_dias)