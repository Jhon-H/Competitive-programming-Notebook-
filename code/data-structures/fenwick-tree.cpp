#include "template.h";

struct FenwickTree { // 0-indexed
  int N = 1e5;
  vi bit;

  FenwickTree() {
    bit = vi(N, 0);
  }

  FenwickTree(vi &arr) { // nlogn
    for(int i=0; i<N; ++i) {
      add(i, arr[i]);
    }
  }

  ll sum(int where) {
    ll val = 0;
    for(++where; where > 0; where -= where & -where) {
      val += bit[where];
    }  
  }

  ll sum(int l, int r) {
    return sum(r) - (l == 0 ? 0 : sum(l-1));
  }

  void add(int where, int what) {
    for(++where; where <= N; where += where & -where)  {
      bit[where] += what;
    }
  }
};