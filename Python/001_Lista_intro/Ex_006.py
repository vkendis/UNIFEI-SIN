"""
6) Fazer um algoritmo para calcular o novo salário de um funcionário. Sabe-se que os funcionários que ganham 
até R$ 1000,00 terão aumento de 20%, e os demais terão aumento de 10%. 
"""
print("Difite o salario do funcionario: ")
salario = float(input())

if salario <= 1000:
    salario = salario*1.2
    print(salario)
else:
    salario = salario*1.1
print("O novo salario sera igual a: {:.2f} reais".format(salario))