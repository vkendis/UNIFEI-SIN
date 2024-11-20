import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from itertools import combinations

# Carregamos o arquivo CSV contendo os dados de ocorrências criminais
df = pd.read_csv("dataset_filtrado.csv", delimiter=';', encoding='utf-8')

# Filtramos os registros onde 'AREA NAME' é 'Hollywood'
df_Hollywood = df[df['AREA NAME'] == 'Hollywood'].copy()

# Exibimos os valores ausentes em cada coluna para diagnóstico
print("Valores ausentes antes do preenchimento:")
print(df_Hollywood.isna().sum())

# Selecionamos uma amostra aleatória de 1000 registros com seed 42 para garantir consistência nos resultados
df_sampled = df_Hollywood.sample(n=1000, random_state=42).reset_index(drop=True)

# Preenchemos valores ausentes separadamente para cada coluna
for column in df_sampled.columns:
    # Para colunas de texto, substituímos valores ausentes por 'missing'
    if df_sampled[column].dtype == 'object':
        df_sampled[column].fillna('missing', inplace=True)
    # Para colunas numéricas, substituímos valores ausentes por 0
    else:
        df_sampled[column].fillna(0, inplace=True)

# Armazenamos os valores originais dos atributos categóricos
# Isso nos permite preservar os dados originais para futuras análises
original_values = {column: df_sampled[column].copy() for column in df_sampled.columns}

# Codificamos os atributos categóricos para facilitar a comparação numérica
label_encoders = {}
for column in df_sampled.columns:
    le = LabelEncoder()
    df_sampled[column] = le.fit_transform(df_sampled[column].astype(str))
    label_encoders[column] = le

# Inicializamos um grafo vazio utilizando a biblioteca NetworkX
G = nx.Graph()

# Adicionamos os nós ao grafo, utilizando 'DR_NO' como identificador único de cada nó
for idx, row in df_sampled.iterrows():
    dr_no = row['DR_NO']  # Usamos 'DR_NO' como identificador único
    # Substituímos os valores codificados pelos valores originais e armazenamos como atributos do nó
    original_attrs = {col: original_values[col].iloc[idx] for col in df_sampled.columns if col != 'DR_NO'}
    G.add_node(dr_no, **original_attrs)  # Adicionamos o nó com seus atributos associados

# Adicionamos arestas entre pares de nós, calculando o peso com base na similaridade dos atributos
for (dr_no1, data1), (dr_no2, data2) in combinations(G.nodes(data=True), 2):
    # Contamos o número de atributos iguais entre os dois nós, ignorando valores 'missing'
    weight = sum(1 for key in data1 if data1[key] == data2[key] and data1[key] != 'missing')
    # Adicionamos uma aresta apenas se houver atributos iguais (peso > 0)
    if weight > 0:
        G.add_edge(dr_no1, dr_no2, weight=weight)

# Definimos o layout do grafo utilizando o algoritmo spring_layout para melhorar a visualização
pos = nx.spring_layout(G, seed=42)  # Usamos seed para garantir a reprodutibilidade

# Criamos uma figura para plotar o grafo
plt.figure(figsize=(12, 12))
edges = G.edges(data=True)  # Obtemos as arestas do grafo com os dados associados
weights = [edge[2]['weight'] for edge in edges]  # Extraímos os pesos das arestas

# Desenhamos o grafo, configurando os nós, as arestas e os pesos
nx.draw(
    G, 
    pos, 
    with_labels=False, 
    node_size=50, 
    node_color='blue', 
    edge_color=weights, 
    edge_cmap=plt.cm.Blues, 
    alpha=0.7
)

# Adicionamos um título ao gráfico e exibimos a figura
plt.title('Grafo de Incidentes Criminais em N Hollywood')
plt.show()

# Salvamos o grafo em formato GraphML, incluindo os valores originais como atributos
graphml_filename = 'Hollywood_graph_original.graphml'
nx.write_graphml(G, graphml_filename, encoding='utf-8', prettyprint=True)
print(f"Grafo salvo no arquivo '{graphml_filename}'.")
