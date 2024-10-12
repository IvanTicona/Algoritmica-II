# Maximo Flujo

## Ford Fulkerson

pseudo-código:

setup directed residual graph with edge capacity = original edge weights
mf = 0 // an iterative algorithm
while (there exists an augmenting path p from s to t)
// p is a path from s->t that passes through +ve edges in residual graph
augment/send flow f along the path p (s -> ... -> i -> j -> ... t)
// let f = the edge weight i-j that is the minimum along the path p
1. decrease capacity of forward edges (e.g., i, j) along path p by f
2. increase capacity of backward edges (e.g., j, i) along path p by f
3. mf += f // increase mf
output mf

Podemos decir que al agregar el residual graph estamos convirtiendo el grafo original direccionado en un grafo no direccionado?

The reason for decreasing the capacity of forward edges is obvious. By sending a flow
through augmenting path p, we will decrease the remaining (residual) capacities of the
(forward) edges used in p. The reason for increasing the capacity of backward edges may not
be that obvious, but this step is important for the correctness of Ford-Fulkerson method.
By increasing the capacity of a backward edge (j, i), Ford-Fulkerson method allows future
iterations (flows) to cancel (part of) the capacity used by a forward edge (i, j) that was
incorrectly used by some earlier flow(s). (Podemos decir que es grafo residual corrige los errores de los flujos anteriores?)

Complejidad: O(mf * E) donde mf es el flujo máximo y E es el número de aristas.

## Edmonds-Karp

Edmonds-Karp es una implementación de Ford-Fulkerson que utiliza BFS para encontrar el camino de aumento más corto.