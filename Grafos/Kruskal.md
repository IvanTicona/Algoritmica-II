# Algoritmo Kruskal MST

De un grafo dado el cual es ponderado, conectado y no dirigido, se busca encontrar el árbol de expansión mínima (MST) es decir las aristas que forman un subgrafo que es un árbol y que conecta todos los vértices del grafo original, con el menor peso posible.

Para que conserve la conectividad necesitamos V-1 aristas, donde V es el numero de nodos del grafo, donde estos forman un árbol y este cubre todos los nodos.

Pueden haber muchos spanning trees posibles, DFS y BFS spanning trees, SSSP spanning trees, pero entre todos estos hay almenos un MST.