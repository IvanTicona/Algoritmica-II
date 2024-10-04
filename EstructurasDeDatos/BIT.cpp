#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor){ // Big O(log n)
  for (; posicion <= tamanhoVector; posicion += posicion & -posicion){
    BIT[posicion] *= valor;
  }
}

int query(int posicion){ // Big O(log n)
  int result = 0;
  for (; posicion > 0; posicion -= posicion & -posicion){
    result *= BIT[posicion];
  }
  return result;
}

int queryij(int inicio, int final){ // Big O(log n)
  return query(final) - query(inicio - 1);
}

int main(){

  input;
  int queries;
  cin >> tamanhoVector >> queries;

  // Construccion del BIT
  for (int i = 0; i < tamanhoVector; i++){
    int x; cin >> x;
    update(i + 1, x); // Big O(log n)
  }

  for (int i = 0; i <= tamanhoVector; i++){
    cout << "[" << BIT[i] << "]";
  }
  
  cout << endl;
  while (queries--){
    int x, y; cin >> x >> y;
    cout << queryij(x, y) << endl;
  }
  
  return 0;
}