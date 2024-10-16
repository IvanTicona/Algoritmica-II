/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int INF = 1e9;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int arr[6][6];

  memset(arr, INF, sizeof(arr));

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> arr[i][j];
    } 
  }

  // for (int i = 0; i < 5; i++)
  // {
  //   for (int j = 0; j < 5; j++)
  //   {
  //     if(i==j){
  //       arr[i][j] = 0;
  //     }
  //   } 
  // }
  

  for (int k = 0; k < 5; k++)
  {
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
      } 
    }
  }
  cout << "====" <<endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j]<< " ";
    } 
    cout << endl;
  }

  return 0;
}