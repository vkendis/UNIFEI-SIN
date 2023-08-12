"""
6) Faça um programa que leia o salário de um trabalhador e o valor da prestação de um empréstimo. Se a
prestação for maior que 20% de seu salário, mostre a mensagem: “emprestimo nao concedido”. Caso
contrário, mostre a mensagem: “emprestimo concedido”
"""

salario = float(input("Digite o salario: "))
parcela = float(input("Digite a parcela: "))

if parcela > 0.2*salario:
    print("Emprestimo não Concedido")
else: 
    print("Emprestimo  concedido")
