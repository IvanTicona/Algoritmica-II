# Union Find

int find(int node){
  int father = parent[node];
  if(node == father) return node;
  else return parent[node] = find(father);
}

void union(int a, int b){
  int A = find(a);
  int B = find(b);
  if(A == B) return;
  if(rank[A] < rank[B]) swap(A, B);
  parent[B] = A;
  if(rank[A] == rank[B]) rank[A]++;
}

bool sameGroup(int a, int b){
  return find(a) == find(b);
}

int count(int node){
  int c=0;
  int NODE = find(node);
  for(int i = 0; i < parent.size(); i++){
    if(find(i) == NODE) c++;
  }
  return c;
}


KRUSKAL, BACKTRACKING
