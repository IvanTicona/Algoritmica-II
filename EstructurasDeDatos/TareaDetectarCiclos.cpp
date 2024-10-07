
#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

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

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  //Detectar si un grafo tiene ciclos
  int n; cin>>n;
  UnionFind UF(n);
  bool hasCycle = false;
  for(int i = 0; i < n; i++) {
    int u, v; cin>>u>>v;
    if(UF.isSameSet(u, v)) {
      hasCycle = true;
      break;
    }
    UF.unionSet(u, v);
  }
  cout<<(hasCycle ? "Si tiene ciclos" : "No tiene ciclos")<<endl;

  return 0;
}