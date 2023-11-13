#include "template.h";

// struct SegTreeLazy {
//   const int MAXN = 1e5;
//   vi t, lazy;

//   SegTreeLazy() {
//     t = vi(MAXN*4, 0);
//     lazy= vi(MAXN*4, 0);
//   }

//   void push(int v) {
//     if(lazy[v]) {
//       t[v<<1] += lazy[v];
//       lazy[v<<1] += lazy[v];
//       t[(v<<1)|1] += lazy[v];
//       lazy[(v<<1)|1] += lazy[v];
//       lazy[v] = 0;
//     }
//   }

//   int op(int a, int b) { return a+b; }

//   void build(vi &arr, int v, int tl, int tr) {
//     if(tl == tr) {
//       t[v] = arr[tl];
//     } else {
//       int tm = (tl+tr)>>1;

//       build(arr, v<<1, tl, tm);
//       build(arr, (v<<1)|1, tm+1, tr);

//       t[v] = op(t[v<<1], t[(v<<1)|1]);
//     }
//   }

//   void update(int v, int tl, int tr, int l, int r, int value) {
//     if (l > r) return;
//     if (l == tl && tr == r) {
//       t[v] += value;
//       lazy[v] += value;
//     } else {
//       push(v);
//       int tm = (tl + tr)>>1;

//       update(v<<1, tl, tm, l, min(r, tm), value);
//       update((v<<1)|1, tm+1, tr, max(l, tm+1), r, value);

//       t[v] = op(t[v<<1], t[(v<<1)|1]);
//     }
//   }

//   int query(int v, int tl, int tr, int l, int r) {
//     if (l > r) return 0; // Null value
//     if (l == tl && tr == r) return t[v];

//     push(v);
//     int tm = (tl + tr)>>1;

//     return op(
//       query(v<<1, tl, tm, l, min(r, tm)), 
//       query((v<<1)|1, tm+1, tr, max(l, tm+1), r)
//     );
//   }
// };
