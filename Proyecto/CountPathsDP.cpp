/*
Author: Ivan Ticona
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

vector<int> adjList[MAX_N]; // Complejidad de almacenamiento: O(n + m), donde n es el número de nodos y m el de aristas.
int dp[MAX_N][MAX_N]; // Complejidad de almacenamiento: O(n^2).

// Inicializamos dp con -1 para indicar que aún no se ha calculado ningún camino
void initializeDP(int n){ // Complejidad: O(n^2)
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      dp[i][j] = -1;
    }
  }
  // Complejidad total: O(n^2) ya que recorre cada par de nodos (i, j) una vez.
}

int countPaths(int start, int end){

  // Si start y end son iguales, entonces hay un solo camino
  if (start == end){
    return 1;
  }
  // Si ya se ha calculado el número de caminos entre start y end, retornamos el valor almacenado
  if (dp[start][end] != -1){
    return dp[start][end];
  }

  int paths = 0;
  // Recorremos los vecinos de start y sumamos los caminos que se pueden formar desde cada vecino
  for (int i = 0; i < adjList[start].size(); i++){
    int neighbor = adjList[start][i];
    paths += countPaths(neighbor, end);
  }

  // Almacenamos el número de caminos entre start y end
  dp[start][end] = paths;

  return paths;
}

int main(){

  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int NODES, EDGES;
  // Leemos el número de nodos y aristas
  cin >> NODES >> EDGES;

  initializeDP(NODES); // Inicializamos la matriz de DP Complejidad: O(n^2)
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
    // Calculamos el número de caminos entre from y to
    int totalPaths = countPaths(from, to); // Complejidad depende de la estructura del grafo: O(n^2 + m)
    cout << totalPaths << endl;
  }

  return 0;
}
