#include<bits/stdc++.h>

using namespace std;

/*
// int l=7;
// vector<int> val={2,3,7,9,4};

// int sum(int suma, int pos){
//   if(suma==l) return 1;
//   if(pos>=val.size()) return 0;

//   int sol = sum(suma, pos+1);
//   if(suma+val[pos]<=l){
//     sol += sum(suma+val[pos], pos+1);
//   }
//   return sol;
// }

// vector<char> letras={'p', 'b', 'b', 'd', 'e', 'p', 'p', 'p', 'z', 'n'};
// string palabra="pala";

// bool contain(string p, char x){
//   for (int i = 0; i < p.size(); i++){
//     if(p[i]==x) return true;
//   }
//   return false;
// }

// int verificar(string acc, int i){
//   if(acc.size()==palabra.size()) return 1;
//   if(i>=letras.size()) return 0;
//   int ver = verificar(acc, i + 1);
//   if(contain(palabra, letras[i])){
//     ver+=verificar(acc+letras[i],i+1);
//   }
//   return ver;
// }
*/

typedef vector<int> vi;
typedef vector<vi> vvi;

vi numbers(10);
vector<bool> vis(10);
int k;

void f(vi estado, vvi &soluciones){
  if(estado.size()==k){
    soluciones.push_back(estado);
  }

  for (int i = 0; i < numbers.size(); i++){
    if(!vis[i] && estado.size()<k){
      estado.push_back(numbers[i]);
      vis[i]=true;
      f(estado, soluciones);
      //backtracking
      estado.pop_back();
      vis[i]=false;
    }
  }
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  for (int i = 0; i < 10; i++){
    cin>>numbers[i];
    vis[i]=false;
  }

  cin>>k;
  vi estado;
  vvi soluciones;
  f(estado, soluciones);

  for (int i = 0; i < soluciones.size(); i++){
    cout<<"[";
    for (int j = 0; j < k; j++){
      cout<<(j>0? ", ": "")<<soluciones[i][j];
    }
    cout<<"]"<<endl;
  }

  return 0;
}