/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n; cin >> n;
  string s; cin >> s;
  int coffe = 0, cnt = 0;
  for (char &c: s){
    if(c == '1'){
      coffe++;
    }
  }

  if(coffe>0){
    cout << pow(2, coffe) << endl;
  }else{
    cout << 0 << endl;
  }

  return 0;
}