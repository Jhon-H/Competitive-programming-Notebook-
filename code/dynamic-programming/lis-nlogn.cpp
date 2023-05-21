#include "template.h";

// O(n * log n)
vi get_lis(vi &a, vi &p, int end) {
  vi lis;
  for(int u=end; u != -1; u=p[u]) lis.pb(a[u-1]);
  reverse(ALL(lis));
  return lis;
}

int lis(vi &a) {
  int n = sz(a);
  vi d(n+1, INF), ind(n+1, 0), p(n+1, -1);

  d[0] = -INF;
  ind[0] = -1;
  
  for(int i=0; i<n; ++i) {
    int l = upper_bound(ALL(d), a[i]) - d.begin();
    if(d[l-1] < a[i] && a[i] < d[l]) {
      d[l] = a[i];
      ind[l] = i+1;
      p[i+1] = ind[l-1];
    }
  }

  int ans;
  for(int i=0; i<=n; ++i) {
    if (d[i] < INF) ans = i;
  }

  //vi lis_path = get_lis(a, p, ind[ans]);
  //for(int i: lis_path) cout << i << " "; cout << endl;

  return ans;
}