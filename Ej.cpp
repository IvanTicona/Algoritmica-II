/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int n = 6;
int lugares[6];
int k;

bool f(int dist){
  int contPersona = 1;
  int ultimaPersona = lugares[0];
  for (int i = 0; i < n; i++)
  {
    if(lugares[i] - ultimaPersona -1 >= dist){
      ultimaPersona = lugares[i];
      contPersona++;
    }
  }
  
  return contPersona >= k;
}

int binarySearch(){
  int right = 1000;
  int left = 0;
  while(left < right){
    int mid = (left+right)/2;
    if(f(mid)){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);




  return 0;
}