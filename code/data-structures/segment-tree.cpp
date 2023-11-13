#include "template.h";

struct SegTree {
  const int MAXN = 1e5;
  vi t;

  SegTree() { t = vi(MAXN*2, 0); }

  int op(int a, int b) { return a+b; }

  void build(vi &arr, int v, int tl, int tr) {
    if(tl == tr) {
      t[v] = arr[tl];
    } else {
      int tm = (tl+tr)>>1;
      int rightNode = v+2*(tm-tl+1);
      int leftNode = v+1;

      build(arr, leftNode, tl, tm);
      build(arr, rightNode, tm+1, tr);

      t[v] = op(t[leftNode], t[rightNode]);
    }
  }

  void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
      t[v] = val;
    } else {
      int tm = (tl+tr)>>1;
      int rightNode = v+2*(tm-tl+1);
      int leftNode = v+1;

      if(pos <= tm) update(leftNode, tl, tm, pos, val);
      else update(rightNode, tm+1, tr, pos, val);

      t[v] = op(t[leftNode], t[rightNode]);
    }
  }

  int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0; // Null value
    if(tl == l && tr == r) return t[v];

    int tm = (tl+tr)>>1;
    int rightNode = v+2*(tm-tl+1);
    int leftNode = v+1;

    return op(
      query(leftNode, tl, tm, l, min(tm, r)),
      query(rightNode, tm+1, tr, max(tm+1, l), r)
    );
  }
};