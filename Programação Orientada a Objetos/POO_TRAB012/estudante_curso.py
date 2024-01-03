class Estudante():
  def __init__(self, nroMatric, nome, curso):
    self.nroMatric = nroMatric
    self.nome = nome
    self.curso = curso
  
  @property
  def sigla(self):
    return self.__sigla
  
  @sigla.setter
  def sigla (self, sigla):
    self.__sigla = sigla
  
  @property
  def nome(self):
    return self.__nome
  
  @nome.setter
  def nome (self, nome):
    self.__nome = nome
  
  @property
  def curso(self):
    return self.__curso
  
  @curso.setter
  def curso (self, curso):
    self.__curso = curso

class Curso():
  def __init__(self, sigla, nome):
    self.sigla = sigla
    self.nome = nome
  
  @property
  def sigla(self):
    return self.__sigla
  
  @sigla.setter
  def sigla (self, sigla):
    self.__sigla = sigla
  
  @property
  def nome(self):
    return self.__nome
  
  @nome.setter
  def nome (self, nome):
    self.__nome = nome


class CtrlEstudanteCurso():
  def __init__(self):
    c1 = Curso("CCO", "Ciência da Computação")
    c2 = Curso("SIN", "Sistemas de Informação")
    c3 = Curso("EEL", "Engenharia Elétrica")
    c4 = Curso("ECO", "Engenharia da Computação")

    self.listaCurso = []

    self.listaCurso.append(c1)
    self.listaCurso.append(c2)
    self.listaCurso.append(c3)
    self.listaCurso.append(c4)

    self.listaEstudante = []

    self.listaEstudante.append(Estudante(2001, "Mariana Oliveira", c1))
    self.listaEstudante.append(Estudante(2002, "Pedro Fernandes", c1))
    self.listaEstudante.append(Estudante(2003, "Ana Pereira", c2))
    self.listaEstudante.append(Estudante(2004, "Carlos Silva", c3))
    self.listaEstudante.append(Estudante(2005, "Juliana Costa", c4))
    self.listaEstudante.append(Estudante(2006, "Vinícius Mendes", c1))
    self.listaEstudante.append(Estudante(2007, "Gabriela Lima", c2))
    self.listaEstudante.append(Estudante(2008, "Lucas Rocha", c3))
    self.listaEstudante.append(Estudante(2009, "Amanda Santos", c4))
    self.listaEstudante.append(Estudante(2010, "Fernando Alves", c2))
    self.listaEstudante.append(Estudante(2011, "Camila Oliveira", c3))
    self.listaEstudante.append(Estudante(2012, "Thiago Barbosa", c4))

   
  def listaNroMatric(self):
    listaMatric = []

    for est in self.listaEstudante:
      listaMatric.append(est.nroMatric)
    
    return listaMatric
  
  def listaNomesCursos(self):
    listaNomes = []

    for curso in self.listaCurso:
      listaNomes.append(curso.nome)
    
    return listaNomes
  
  def listaSiglasCursos(self):
    listaSiglas = []

    for curso in self.listaCurso:
      listaSiglas.append(curso.sigla)
    
    return listaSiglas
  
  def getCurso(self, nome):
    cursoRet = None
    for curso in self.listaCurso:
      if curso.nome == nome:
          cursoRet = curso
    return cursoRet
  
  def getCursoSigla(self, sigla):
    cursoRet = None
    for curso in self.listaCurso:
      if curso.sigla == sigla:
          cursoRet = curso
    return cursoRet