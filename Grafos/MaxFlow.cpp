#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;
const ll INF = 1e18; // large enough

class max_flow{
private:
  int V; // Numero de nodos
  vector<edge> EL; //Lista de aristas
  vector<vi> AL;  //Lista de adyacencia
  vi d, last; //distancia y ultimo nodo visitado
  vector<ii> p; //padre

  bool BFS(int s, int t){ // find augmenting path
    d.assign(V, -1); // reiniciar distancia
    d[s] = 0; // distancia a s es 0
    queue<int> q({s}); // cola con s
    p.assign(V, {-1, -1}); // record BFS sp tree
    while (!q.empty()){
      int u = q.front();
      q.pop();
      if (u == t)
        break; // stop as sink t reached
      for (auto &idx : AL[u]){                         // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];                // stored in EL[idx]
        if ((cap - flow > 0) && (d[v] == -1))          // positive residual edge
          d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1; // has an augmenting path
  }
  ll send_one_flow(int s, int t, ll f = INF){ // send one flow from s->t
    if (s == t)
      return f; // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap - flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx ^ 1]); // back edge
    rflow -= pushed;                   // back flow
    return pushed;
  }

public:
  max_flow(int initialV) : V(initialV){ // Constructor
    EL.clear();
    AL.assign(V, vi());
  }
  void add_edge(int u, int v, ll w, bool directed = true){
    if (u == v)
      return;                                // safeguard: no self loop
    EL.emplace_back(v, w, 0);                // u->v, cap w, flow 0
    AL[u].push_back(EL.size() - 1);          // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0); // back edge
    AL[v].push_back(EL.size() - 1);          // remember this index
  }
  ll edmonds_karp(int s, int t){
    ll mf = 0; // mf stands for max_flow
    while (BFS(s, t)){            // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t); // find and send 1 flow f
      if (f == 0)
        break; // if f == 0, stop
      mf += f; // if f > 0, add to mf
    }
    return mf;
  }
};

int main()
{

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  return 0;
}