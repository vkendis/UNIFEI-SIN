"""
9) Um aluno  deseja saber qual  a porcentagem de  faltas que ele tem em uma disciplina. Faça um  programa 
que  leia  a  carga  horária  total  da  disciplina  e  a  quantidade  de  horas  de  faltas  acumuladas,  e  mostre  a 
porcentagem de faltas do aluno (entre 0 a 100).
"""

ch = int(input("Digite a carga horaria: "))
faltas = int(input("Digite a carga de faltas: "))

porcentagem = (faltas/ch)*100
print("A porcentagem de falta do aluno e igual a: {:.2f}%".format(porcentagem))