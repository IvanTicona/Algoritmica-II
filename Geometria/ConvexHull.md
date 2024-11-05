


vector<Point> convex_hull(vector<Point> A){
  
  int n = A.size(), k = 0;

  sort(A.begin(), A.end());

  vector<Point> ans(2*n);

  for(int i = 0; i < n; i++){
    while(k >= 2 && cros(ans[k-2], ans[k-1], A[i]) <= 0) k--;
    ans[k++] = A[i];
  }

  for(int i = n-2, t = k; i >= 0; i--){
    while(k > t && cros(ans[k-2], ans[k-1], A[i]) <= 0) k--;
    ans[k++] = A[i];
  }

  ans.resize(k-1);

  return ans;
}