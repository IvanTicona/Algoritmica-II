#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
vector<int> adjList[MAX_N];
int dp[MAX_N];

void countPathsBottomUp(int start, int n) {

  memset(dp, 0, sizeof(dp)); // Inicializamos la tabla dp en 0
  dp[start] = 1; // Hay exactamente un camino del nodo de inicio a sí mismo

  for (int u = 0; u < n; ++u) { // Complejidad O(n) Recorre todos los nodos del grafo
    for (int neighbor : adjList[u]) { // Complejidad O(E) Para cada nodo recorre sus vecinos (E es el numero de aristas)
        dp[neighbor] += dp[u]; // Sumamos los caminos que llegan a 'u' para extenderlos a 'neighbor'
    }
  }
}

int main(){

  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int NODES, EDGES;
  // Leemos el número de nodos y aristas
  cin >> NODES >> EDGES;

  // Leemos las aristas
  for (int i = 0; i < EDGES; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
  }

  // Leemos el número de consultas
  int queries; cin >> queries;

  for (int i = 0; i < queries; i++){
    int from, to;
    cin >> from >> to;
    // Calculamos el numero de caminos desde el nodo 0 a todos los demás nodos
    countPathsBottomUp(from, NODES);
    // Obtenemos el número de caminos desde el nodo de inicio al nodo de destino
    int totalPaths = dp[to];
    cout << totalPaths << endl;
  }

  return 0;
}