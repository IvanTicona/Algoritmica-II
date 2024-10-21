#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;
const ll INF = 1e18;
ll iteraciones = 0;

class max_flow
{
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi visited;
  vi d, last;
  vector<ii> p;
  bool BFS(int s, int t)
  {
    d.assign(V, -1);
    d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      if (u == t)
        break;
      for (auto &idx : AL[u])
      {                                                
        auto &[v, cap, flow] = EL[idx];                
        if ((cap - flow > 0) && (d[v] == -1))          
          d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; 
      }
    }
    return d[t] != -1;
  }
  ll send_one_flow(int s, int t, ll f = INF)
  { 
    if (s == t)
      return f; 
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap - flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx ^ 1]); 
    rflow -= pushed;                   
    return pushed;
  }
  bool DFS(int u, int t, ll f = INF)
  {
    if (u == t)
      return f;
    visited[u] = 1;
    for (auto &idx : AL[u])
    {
      auto &[v, cap, flow] = EL[idx];           
      if (!visited[v] && cap - flow > 0)
      {
        ll pushed = DFS(v, t, min(f, cap - flow)); 
        if (pushed > 0)
        {
          flow += pushed;
          auto &rflow = get<2>(EL[idx ^ 1]); 
          rflow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV)
  {
    EL.clear();
    AL.assign(V, vi());
  }
  void add_edge(int u, int v, ll w, bool directed = true)
  {
    if (u == v)
      return;                                
    EL.emplace_back(v, w, 0);                
    AL[u].push_back(EL.size() - 1);          
    EL.emplace_back(u, directed ? 0 : w, 0); 
    AL[v].push_back(EL.size() - 1);          
  }
  ll edmonds_karp(int s, int t)
  {
    ll mf = 0; 
    while (BFS(s, t))
    {        
      ll f = send_one_flow(s, t);
      if (f == 0)
        break; 
      mf += f;
      iteraciones++;
    }
    return mf;
  }
  ll ford_fulkerson(int s, int t)
  {
    ll mf = 0; 
    while (true)
    {
      visited.assign(V, 0);
      ll f = DFS(s, t);
      if (f == 0)
        break;
      mf += f;
      iteraciones++;
      // cout << iteraciones << endl;
    }
    return mf;
  }
};

int main(){

  auto start = high_resolution_clock::now();

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int V, E;
  cin >> V >> E;
  max_flow mf(V);
  for (int i = 0; i < E; i++)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    mf.add_edge(u, v , w);
  }

  // ll maxFlow = mf.edmonds_karp(0, V-1);
  ll maxFlow = mf.ford_fulkerson(0, V-1);

  auto end = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(end - start).count();
  cout << "Tiempo de ejecución: " << duration / 1e6 << " segundos" << endl;
  cout << "Iteraciones: " << iteraciones << endl;
  cout << "Max Flow: " << maxFlow << endl;

  return 0;
}
