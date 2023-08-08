""""
5) Fazer um algoritmo para calcular a média aritmética entre duas notas de um aluno e apresentar a sua situação 
(aprovado / reprovado), considerando que o mínimo para a aprovação seja 6.0 pontos.
"""
print("Digite as notas do aluno: ")
n1 = float(input())
n2 = float(input())

media = (n1+n2)/2
print("A media do aluno sera igual a: {:.1f}".format(media))