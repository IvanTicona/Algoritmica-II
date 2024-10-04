
#include<bits/stdc++.h>

using namespace std;

int BIT[10];
int n=8;

void update(int posicion, int valor){
  for (; posicion <= n; posicion += posicion & -posicion){
    BIT[posicion] = max(BIT[posicion], valor);
  }
}

int query(int posicion){
  int result = 0;
  for (; posicion > 0; posicion -= posicion & -posicion){
    result = max(BIT[posicion], result);
  }
  return result;
}

int queryij(int inicio, int final){
  return max(query(final), query(inicio - 1));
}

void showBIT(){
  cout<<"BIT "<<endl;
  cout << "[ ";
  for (int i = 1; i <= n; i++){
    cout << BIT[i] << " ";
  }
  cout << "]" << endl<<endl;
}

int main(){

  //Precios de los productos
  vector<int> prices = {0, 2, 5, 1, 6, 3, 7, 4, 9};

  //Construccion del BIT
  for (int i = 1; i <= n; i++){
    update(i, prices[i]);
  }
  showBIT();

  //Consultas y actualizaciones
  cout<<"max(1,4) = "<<queryij(1, 4)<<endl<<endl;
  update(5, 10);
  showBIT();
  queryij(3, 7);
  cout<<"max(3,7) = "<<queryij(3, 7)<<endl<<endl;

  return 0;
}