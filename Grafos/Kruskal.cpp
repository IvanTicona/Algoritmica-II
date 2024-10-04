#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;

class UnionFind{ // OOP style
private:
  vi p, rank, setSize; // vi p is the key part
  int numSets;

public:
  UnionFind(int N){
    p.assign(N, 0);
    for (int i = 0; i < N; ++i)
      p[i] = i;
    rank.assign(N, 0);    // optional speedup
    setSize.assign(N, 1); // optional feature
    numSets = N;          // optional feature
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int numDisjointSets() { return numSets; }            // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
  void unionSet(int i, int j){
    if (isSameSet(i, j))
      return;                           // i and j are in same set
    int x = findSet(i), y = findSet(j); // find both rep items
    if (rank[x] > rank[y])
      swap(x, y); // keep x ’shorter’ than y
    p[x] = y;     // set x under y
    if (rank[x] == rank[y])
      ++rank[y];              // optional speedup
    setSize[y] += setSize[x]; // combine set sizes at y
    --numSets;                // a union reduces numSets
  }
};

int main(){

  int V, E; scanf("%d %d", &V, &E);
  vector<iii> EL(E); // Lista de Aristas

  for (int i = 0; i < E; ++i){
    int u, v, w; scanf("%d %d %d", &u, &v, &w); // Leemos arista, nodos y peso (u, v, w)
    EL[i] = {w, u, v};             // Reordenamos (w, u, v)
  }
  sort(EL.begin(), EL.end()); // Ordenamos por peso O(E log E)

  int mst_cost = 0, num_taken = 0; // Ninguna arista es tomada
  UnionFind UF(V);                 // Todos los nodos son conjuntos disjuntos

  for (auto &[w, u, v] : EL){
    if (UF.isSameSet(u, v)) continue; // Ya estan en conectados
    mst_cost += w;     // Sumamos el peso de la arista
    UF.unionSet(u, v); // Unimos los nodos
    ++num_taken;       // 1 aristas mas tomada
    if (num_taken == V - 1) break; // Ya tenemos el MST, optimizacion
  }
  // Nota: Eventualmente el numero de conjuntos disjuntos es 1 para ser un MST
  printf("MST cost = %d (Kruskal’s)\n", mst_cost);

  return 0;
}