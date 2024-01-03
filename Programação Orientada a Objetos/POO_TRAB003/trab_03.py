#Vinicius Kendi Sasaki
#2023013498
from abc import ABC, abstractmethod

class EmpDometica(ABC):
    def __init__(self, nome, telefone):
        self.__nome = nome
        self.__telefone = telefone

    @property
    def nome(self):
        return self.__nome
    
    @nome.setter
    def nome(self, nome):
        self.__nome = nome

    @property
    def telefone(self):
        return self.__telefone
    
    @telefone.setter
    def telefone(self, telefone):
        self.__telefone = telefone
    
    @abstractmethod
    def getSalario(self):
        pass

class Horista(EmpDometica):
    def __init__(self, nome, telefone, horasTrabalhadas, valorPorHora):
        super().__init__(nome, telefone)
        self.__horasTrabalhadas = horasTrabalhadas
        self.__valorPorHora = valorPorHora

    @property
    def horasTrabalhadas(self):
        return self.__horasTrabalhadas
    
    @property
    def valorPorHora(self):
        return self.__valorPorHora
    
    def getSalario(self):
        return self.__horasTrabalhadas * self.__valorPorHora
    
class Diarista(EmpDometica):
    def __init__(self, nome, telefone, diasTrabalhados, valorPorDia):
        super().__init__(nome, telefone)
        self.__diasTrabalhados = diasTrabalhados
        self.__valorPorDia = valorPorDia

    @property
    def diasTrabalhados(self):
        return self.__diasTrabalhados
    
    @property
    def valorPorDia(self):
        return self.__valorPorDia
    
    def getSalario(self):
        return self.__diasTrabalhados * self.__valorPorDia
    
class Mensalista(EmpDometica):
    def __init__(self, nome, telefone, valorMensal):
        super().__init__(nome, telefone)
        self.__valorMensal = valorMensal

    @property
    def valorMensal(self):
        return self.__valorMensal
    
    def getSalario(self):
        return self.__valorMensal
    
if __name__ == "__main__":
    emp1 = Horista('Claudio', 998544512, 160, 12)
    emp2 = Diarista('Lucia', 918547845, 20, 65)
    emp3 = Mensalista('Agenor', 964878592, 1200)
    empregados = [emp1, emp2, emp3]
    for emp in empregados:
        print('Nome: {} - Salario: {}'.format(emp.nome, emp.getSalario()))

    melhorCusto = min(empregados, key=lambda emp: emp.getSalario())
    print('A melhor opcao para o orcamento de empregado para a republica e: {} - {} - {}'.format(melhorCusto.nome, melhorCusto.telefone, melhorCusto.getSalario()))