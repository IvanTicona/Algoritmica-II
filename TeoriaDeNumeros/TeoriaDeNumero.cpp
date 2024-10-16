/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

long long gcd(long a, long b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}

// long long gcdExt(long a, long b){

// }

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int a, b, c; cin >> a >> b >> c;
  // cout << gcd(a,b) << endl;

  for (int i = 0; i < c; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if(a*i+b*j == 1200){
        cout << "Es solucion: x = " << i << " y = " << j << endl;
        return 0;
      }
    }
    
  }
  

  return 0;
}