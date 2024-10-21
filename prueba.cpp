/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int x = 11023;

  int left = 0;
  int right = 20000;
  int cnt = 0;

  while (true)
  {
    cnt++;
    int mid = (left+right)/2;
    if(mid == x){
      break;
    }else if(mid > x){
      right = mid - 1;
    }else{
      left = mid + 1;
    }
  }

  cout << cnt << endl;

  return 0;
}