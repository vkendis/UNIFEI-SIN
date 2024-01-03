#VINICIUS KENDI SASAKI
#2023013498

from abc import ABC, abstractmethod

class Conta(ABC):
    def __init__(self, numero, nome, saldo):
        self.__numero = numero
        self.__nome = nome
        self.__saldo = saldo
        self.__listaTransacoes = []

    @property
    def numero(self):
        return self.__numero

    @property
    def nome(self):
        return self.__nome

    @property
    def saldo(self):
        return self.__saldo

    def deposito(self, valor):
        operacao = Transacao(valor)
        self.__saldo += valor
        self.__listaTransacoes.append(operacao)

    def retirada(self, valor):
        if self.__saldo > valor:
            operacao = Transacao(-valor)
            self.__saldo -= valor
            self.__listaTransacoes.append(operacao)
        else:
            print("Saldo insuficiente!")

    def getTransacoes(self):
        return self.__listaTransacoes

class Comum(Conta):
    pass

class Limite(Conta):
    def __init__(self, numero, nome, saldo, valorLimite):
        super().__init__(numero, nome, saldo)
        self.__valorLimite = valorLimite

    @property
    def valorLimite(self):
        return self.__valorLimite

class Poupanca(Conta):
    def __init__(self, numero, nome, saldo, aniversario):
        super().__init__(numero, nome, saldo)
        self.__aniversario = aniversario

    @property
    def aniversario(self):
        return self.__aniversario

class Transacao:
    def __init__(self, valor):
        self.__valor = valor

    @property
    def valor(self):
        return self.__valor

if __name__ == "__main__":
    #Exemplo da aplicação
    conta = Comum("123", "Alberto", 20000)
    conta.deposito(500)
    conta.retirada(200)
    print(f"Saldo: {conta.saldo}")
