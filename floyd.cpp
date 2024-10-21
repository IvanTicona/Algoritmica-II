/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int INF = 1e9;

int main(){

  // freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int floy[5][5] = {
    {0, 3, 8, INF, -4},
    {INF, 0, INF, 1, 7},
    {INF, 4, 0, INF, INF},
    {2, INF, -5, 0, INF},
    {INF, INF, INF, 6, 0}
  };

  //FLOYD WARSHALL

  for (int k = 0; k < 5; k++)
  {
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if(floy[i][k] != INF && floy[k][j] != INF){
          floy[i][j] = min(floy[i][j], floy[i][k] + floy[k][j]);
        }
      }
    }
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << floy[i][j] << " ";
    }
    cout << endl;
  }


  return 0;
}