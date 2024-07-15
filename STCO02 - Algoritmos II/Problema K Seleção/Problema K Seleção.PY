# Vinícius Kendi Sasaki - 2023013498
# Laviny Rodrigues Laurindo - 2023012893
import random

#Objetivo: Seguindo as dicas dadas em aula no dia 24/05, procuramos tentar evitar a busca de item por item e cair em redundâncias
#fazendo um método baseado em busca dos elementos de forma simultânea
#Encontramos o QuickSelectMulti que consiste em dividir o array baseado no pivo medio em duas sublistas, menores e maiores que pivo.
#Recursivamente cada sub list(menores e maiores) terá novos particionamentos sendo executados para buscas dos elementos.
#SelectionSort para garantir ordenação dos índices encontrados

#Primeiro Código:
# Insertion Sort é usado para ordenar o array A
# Complexidade O(n^2): Dificulta otimização do tempo quando usamos amostras muito grandes 
# Insertion Sort demora porque cada novo elemento pode precisar de muitas trocas e comparações com tudo que já foi organizado.

#Segundo Código (QuickSelectMulti)
# O QuickSelectMulti é uma extensão do QuickSelect, usado para encontrar múltiplos k-ésimos elementos menores simultaneamente no array A.
# Esta versão é mais eficiente para buscar múltiplos elementos específicos em listas grandes, mantendo a vantagem de não precisar ordenar o array inteiro.
#Complexidade O(n): onde n será o número de elementos do array. O algoritmo tenta dividir a cada particionamento o array em 2. Sempre na metade do array da chamada anterior.
# QuickSelectMulti é rápido porque segmenta o array para focar apenas nas partes necessárias para encontrar os elementos desejados, sem revisitar segmentos desnecessários.

# Ultimo versionamento com selection sort para garantir a ordenação dos índices
# que podem não estar ordenados após o quickSelectMulti().

#Conclusão da alteração dos métodos
# A alteração para QuickSelectMulti é ideal quando precisamos de acesso direto a múltiplos elementos específicos sem a necessidade de visualizar ou usar o array inteiro ordenado.

# Função para particionar o array com base em um pivô
def particionar(array, inicio, fim):
    # Escolhe o elemento do meio como pivô e troca com o último elemento
    meio = (inicio + fim) // 2
    array[meio], array[fim] = array[fim], array[meio]
    pivo = array[fim]
    i = inicio - 1
    # Reorganiza o array para que elementos menores que o pivô fiquem à esquerda
    for j in range(inicio, fim):
        if array[j] <= pivo:
            i += 1
            array[i], array[j] = array[j], array[i]
    # Coloca o pivô de volta à sua posição correta e retorna essa posição
    array[i + 1], array[fim] = array[fim], array[i + 1]
    return i + 1

# Função que encontra os k-ésimos elementos menores usando a estratégia de particionamento para múltiplos índices
def quickSelectMulti(array, inicio, fim, indices):
    if inicio <= fim:
        indicePivo = particionar(array, inicio, fim)
        menores = [k for k in indices if k < indicePivo]
        maiores = [k for k in indices if k > indicePivo]
        if menores:
            quickSelectMulti(array, inicio, indicePivo - 1, menores)
        if maiores:
            quickSelectMulti(array, indicePivo + 1, fim, maiores)

# Função de ordenação por inserção, boa para listas pequenas
def insertion_sort(l):
    # Vai inserindo cada elemento na sua posição correta
    for i in range(1, len(l)):
        j = i
        while j > 0 and l[j] < l[j-1]:
            # Troca os elementos até que o menor esteja na posição correta
            l[j], l[j-1] = l[j-1], l[j]
    return

# Função do Selection Sort para garantir que os resultados da saída
# sejam ordenados corretamente após o método do quickSelectMulti()
# Como o quickSelectMulti encontra os elementos específicos (k-ésimos menores) mas não os ordena entre si,
# o Selection Sort é usado para colocar esses elementos em ordem crescente.
def selection_sort(array):
    n = len(array)
    for i in range(n):
        min_indice = i
        for j in range(i+1, n):
            if array[j] < array[min_indice]:
                min_indice = j
        array[i], array[min_indice] = array[min_indice], array[i]
#Parte do código original 
def main():
    n, k = map(int, input().strip().split())
    random.seed(48 + n + k)
    A = [random.randint(0, 2**48) for _ in range(n)]
    i = [random.randint(1, n) - 1 for _ in range(k)]
    insertion_sort(i)

# Procura indices
    quickSelectMulti(A, 0, len(A) - 1, i)
    resultados = [A[indice] for indice in i]
# Ordena os índices encontrados
    selection_sort(resultados)

# Printa os indices encontrados e ordenados
    print(*resultados)

if __name__ == "__main__":
    main()
