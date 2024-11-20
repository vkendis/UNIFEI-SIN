import networkx as nx
import community as community_louvain
import matplotlib.pyplot as plt
import numpy as np

# Definimos a semente global para garantir a reprodutibilidade dos resultados
np.random.seed(42)

# Carregamos o grafo a partir do arquivo GraphML
graphml_filename = 'Hollywood_graph_original.graphml'
G = nx.read_graphml(graphml_filename)

# Aplicamos o algoritmo de Louvain para detecção de comunidades, garantindo uma semente fixa
partition = community_louvain.best_partition(G, weight='weight', random_state=42)

# Adicionamos a informação de comunidade como atributo dos nós
nx.set_node_attributes(G, partition, 'community')

# Definimos as cores para representar as comunidades detectadas
communities = set(partition.values())
colors = plt.cm.rainbow(np.linspace(0, 1, len(communities)))
color_map = {community: color for community, color in zip(communities, colors)}

# Mapeamos a cor de cada nó com base na comunidade a que pertence
node_colors = [color_map[partition[node]] for node in G.nodes()]

# Desenhamos o grafo, destacando as comunidades
plt.figure(figsize=(12, 12))
pos = nx.spring_layout(G, seed=42)  # Garantimos a consistência do layout com uma semente fixa
nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=50, alpha=0.8)
nx.draw_networkx_edges(G, pos, alpha=0.5)
plt.title('Detecção de Comunidades com o Algoritmo de Louvain')
plt.show()
