#include "template.h";

struct FenwickTree2D { // 0-indexed
  int N = 1e5, M = 1e5;
  vector<vi> bit;

  FenwickTree2D() {
    bit = vector<vi>(N, vi(M, 0));
  }

  ll sum(int x, int y) { // [0, x], [0, y]
    ll val = 0;
    for(int i = x+1; i > 0; i -= i & -i) {
      for(int j = y+1; j > 0; j -= j & -j) {
        val += bit[i][j];
      }
    }
    return val;
  }

  void add(int x, int y, ll delta) {
    for(int i = x+1; i <= N; i += i & -i) {
      for(int j = y+1; j <= M; j += j & -j) {
        bit[i][j] += delta;
      }
    }
  }
};
