#include "template.h";

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

int op(int a, int b) { return a + b; };

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = op(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0; // init INF para max/min
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = op(res, t[l++]);
    if (r&1) res = op(res, t[--r]);
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[n+i];
  build();

  // modify(0, 1);
  // cout << query(3, 11) << endl;
  return 0;
}