#include<bits/stdc++.h>

using namespace std;

vector<int> BIT;
int tamanioVector=BIT.size();

void update(int posicion, int valor){
  for(; posicion <= tamanioVector; posicion += posicion&-posicion){
    BIT[posicion] += valor;
  }
}

int rsq(int posicion){
  int suma = 0;
  for(; posicion > 0; posicion -= posicion&-posicion){
    suma += BIT[posicion];
  }
  return suma;
}

int rsq(int a, int b){
  return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}

int main(){

  return 0;
}