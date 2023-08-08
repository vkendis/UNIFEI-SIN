"""
9) Fazer um algoritmo que receba o ano de nascimento de uma pessoa e o ano atual (dois valores de entrada). A 
seguir, calcular e mostrar: a) a idade da pessoa em anos. b) a idade da pessoa em meses. c) a idade da pessoa 
em dias.
"""
print("Digite o ano atual e o seu ano de nascimento: ")
ano_atual = int(input())
ano_nas = int(input())

idade_em_anos = ano_atual-ano_nas
print("A sua idade e: ", idade_em_anos)

idade_em_meses = idade_em_anos*12
print("A idade em meses e igual a: ", idade_em_meses)

bissexto = idade_em_anos/4
idade_em_dias = (idade_em_anos*365) - bissexto
print("A idade em dias sera aproximadamente: ", idade_em_dias)