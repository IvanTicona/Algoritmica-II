# MST Minimo Arbol de Expansión (Covertura)

De un grafo dado el cual es ponderado, conectado y no dirigido, se busca encontrar el árbol de expansión mínima (MST) es decir las aristas que forman un subgrafo que es un árbol y que conecta todos los vértices del grafo original, con el menor peso posible.

Para que conserve la conectividad necesitamos V-1 aristas, donde V es el numero de nodos del grafo, donde estos forman un árbol y este cubre todos los nodos.

Pueden haber muchos spanning trees posibles, DFS y BFS spanning trees, SSSP spanning trees, pero entre todos estos hay almenos un MST.

## Algoritmo de Kruskal

1. Ordenas todas las aristas en orden no decreciente de acuerdo a su peso.
2. Avariciosamente intentamos agregar cada arista al MST sin formar ciclos.
3. Para saber si una arista forma un ciclo, podemos usar Union-Find.

Runtime: O(sorting + trying to add each edge * cost of UF operations)
         O(E log E + E * ~= 1) = O(E log E) = O(E log (V^2)) = O(2 * E log V) = O(E log V)


Listar 4 aplicaciones del TRIE