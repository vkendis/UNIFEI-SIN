"""
11) Faça um programa que leia a idade e o tempo de serviço de um trabalhador e escreva se ele pode ou não
se aposentar. As condições para aposentadoria são:
• Ter pelo menos 65 anos,
• Ou ter trabalhado pelo menos 30 anos,
• Ou ter pelo menos 60 anos e trabalhado pelo menos 25 anos.
Seu programa deve imprimir apenas as respostas “sim” ou “nao”.
"""
idade = int(input("Insira a idade do usuario: "))
tempo = int(input("Insira o tempo de servico do usuario: "))

if (idade >= 65 or tempo >= 30) or (idade >= 60 and tempo >= 25):
    print("Sim")
else: 
    print("Nao")
