#Vinícius Kendi Sasaki
#2023013498

class Funcionario:
    def __init__(self, codigo, nome):
        self.codigo = codigo
        self.nome = nome
        self.pontos = {}

    def adicionaPonto(self, mes, ano, faltas, atrasos):
        self.pontos[(mes, ano)] = PontoFunc(mes, ano)
        self.pontos[(mes, ano)].lancaFaltas(faltas)
        self.pontos[(mes, ano)].lancaAtrasos(atrasos)

    def lancaFaltas(self, mes, ano, faltas):
        self.pontos[(mes, ano)].lancaFaltas(faltas)
    
    def lancaAtrasos(self, mes, ano, atrasos):
        self.pontos[(mes, ano)].lancaAtrasos(atrasos)

    def imprimeFolha(self, mes, ano):
        pass
        

class Professor(Funcionario):
    def __init__(self, codigo, nome, titulo, salarioHora, nroAulas):
        super().__init__(codigo, nome)
        self.salarioHora = salarioHora
        self.nroAulas = nroAulas
        self.titulo = titulo

    def imprimeFolha(self, mes, ano):
        salario = (self.salarioHora * self.nroAulas) - (self.salarioHora * self.pontos[(mes, ano)].faltas)
        bonusPercentual = 0.10 - 0.01 * self.pontos[(mes, ano)].atrasos
        bonus = salario * bonusPercentual
        print(f"Código: {self.codigo}\nNome: {self.nome}\nSalário: {salario}\nBônus: {bonus}")
    
class TecAdmin(Funcionario):
    def __init__(self, codigo, nome, titulo, salario):
        super().__init__(codigo, nome)
        self.titulo = titulo
        self.salario = salario

    def imprimeFolha(self, mes, ano):
        salario = self.salario - (self.salario/30) * self.pontos[(mes, ano)].faltas
        bonusPercentual = 0.08 - 0.01 * self.pontos[(mes, ano)].atrasos
        bonus = salario * bonusPercentual
        print(f"Código: {self.codigo}\nNome: {self.nome}\nSalário: {salario}\nBônus: {bonus}")

class PontoFunc:
    def __init__(self, mes, ano):
        self.mes = mes
        self.ano = ano
        self.faltas = 0
        self.atrasos = 0

    def lancaFaltas(self, faltas):
        self.faltas += faltas

    def lancaAtrasos(self, atrasos):
        self.atrasos += atrasos

if __name__ == "__main__":
    funcionarios = []
    prof = Professor(1, "Joao", "Doutor", 45.35, 32)
    prof.adicionaPonto(4, 2021, 0, 0)
    prof.lancaFaltas(4, 2021, 2)
    prof.lancaAtrasos(4, 2021, 3)
    funcionarios.append(prof)
    tec = TecAdmin(2, "Pedro", "Analista Contábil", 3600)
    tec.adicionaPonto(4, 2021, 0, 0)
    tec.lancaFaltas(4, 2021, 3)
    tec.lancaAtrasos(4, 2021, 4)
    funcionarios.append(tec)
    for func in funcionarios:
        func.imprimeFolha(4, 2021)
        print()