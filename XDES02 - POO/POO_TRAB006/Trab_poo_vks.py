from abc import ABC, abstractmethod

class TitulacaoInvalida(Exception):
    pass

class IdadeProfInvalida(Exception):
    pass

class CursoIvalido(Exception):
    pass

class IdadeAlunoInvalida(Exception):
    pass

class CpfInvalido(Exception):
    pass

class Pessoa(ABC):
    def __init__(self, nome, end, idade, cpf):
        self.__nome = nome
        self.__end = end
        self.__idade = idade
        self.__cpf = cpf

    @property
    def nome(self):
        return self.__nome

    @property
    def end(self):
        return self.__end

    @property
    def idade(self):
        return self.__idade

    @property
    def cpf(self):
        return self.__cpf

    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, end, idade, cpf, titulacao):
        super().__init__(nome, end, idade, cpf)
        self.__titulacao = titulacao

    @property
    def titulacao(self):
        return self.__titulacao

    def printDescricao(self):
        print(f"Nome: {self.nome}")
        print(f"Endereço: {self.end}")
        print(f"Idade: {self.idade}")
        print(f"CPF: {self.cpf}")
        print(f"Titulação: {self.titulacao}")

class Aluno(Pessoa):
    def __init__(self, nome, end, idade, cpf, curso):
        super().__init__(nome, end, idade, cpf)
        self.__curso = curso

    @property
    def curso(self):
        return self.__curso

    def printDescricao(self):
        print(f"Nome: {self.nome}")
        print(f"Endereço: {self.end}")
        print(f"Idade: {self.idade}")
        print(f"CPF: {self.cpf}")
        print(f"Curso: {self.curso}")

if __name__ == "__main__":


    prof1 = Professor("João", "São Paulo", 40, 7592498222, "Doutor")               
    prof2 = Professor("Ana", "Rio de Janeiro", 31, 5424203093, "Doutor")    
    prof3 = Professor("Pedro", "Belo Horizonte", 32, 7653120934, "Mestre")      
    prof4 = Professor("Mariana", "Salvador", 38, 123490155, "Doutor")       
    aluno1 = Aluno("Lucas", "Fortaleza", 17, 2454569282, "CCO")             
    aluno2 = Aluno("Isabela", "Recife", 19, 581935207, "SIN")               
    aluno3 = Aluno("Matheus", "Brasília", 20, 3869018256, "ECO")                 
    aluno4 = Aluno("Larissa", "Manaus", 22, 123490155, "SIN")         

    listaAlunos = [aluno1, aluno2, aluno3, aluno4]
    listaProfs = [prof1, prof2, prof3, prof4]
    cadastro = []
    cadastroCpf = {}

    print("******************** ERRO ********************")

    for aluno in listaAlunos:

        try:
            if aluno.cpf in cadastroCpf:
                raise CpfInvalido
            if aluno.idade < 18:
                raise IdadeAlunoInvalida
            if aluno.curso != "SIN" and aluno.curso != "CCO":
                raise CursoIvalido
            else:
                cadastroCpf[aluno.cpf] = aluno
                cadastro.append(aluno)

        except CpfInvalido:
            print(f"O CPF do aluno é repetido: {aluno.cpf}")
        except IdadeAlunoInvalida:
            print(f"Idade de aluno inválida: {aluno.idade}")
        except CursoIvalido:
            print(f"Curso inválido: {aluno.curso}")

        print()

    for prof in listaProfs:

        try:
            if prof.cpf in cadastroCpf:
                raise CpfInvalido
            if prof.idade < 30:
                raise IdadeProfInvalida
            if prof.titulacao != "Doutor":
                raise TitulacaoInvalida
            else:
                cadastroCpf[prof.cpf] = prof
                cadastro.append(prof)

        except CpfInvalido:
            print(f"O CPF do professor é repetido: {prof.cpf}")
        except IdadeProfInvalida:
            print(f"Idade de professor inválida: {prof.idade}")
        except TitulacaoInvalida:
            print(f"Titulação inválida: {prof.titulacao}")

    print()

    print("******************** Pessoas Cadastradas ********************")
    
    for pessoa in cadastro:
        pessoa.printDescricao()
