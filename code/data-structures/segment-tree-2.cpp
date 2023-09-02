ll nullValue = 0; // -inf for max, inf for min, etc
struct nodeST{
  nodeST *left;
  nodeST *right;
  int l, r;
  ll value, lazy;

  nodeST(vl &v, int l, int r) : l(l), r(r) {
    int m = (l+r)>>1;
    lazy = 0ll;
    if (l!=r) {
      left = new nodeST(v, l, m);
      right = new nodeST(v, m+1, r);
      value = operation(left->value, right->value);
    } else value = v[l];
  }

  ll operation(ll leftValue, ll rightValue) {
    return leftValue+rightValue;
  } // change operation!!!!

  void propagate() {
    if (lazy) {
      value += lazy*(r-l+1); // += or = ???
      if (l!=r) left->lazy+=lazy, right->lazy+=lazy;
      lazy = 0;
    }
  }

  ll get(int a, int b) {
    propagate();
    if (l>b || r<a) return nullValue;
    if (l>=a && b>=r) return value;
    return operation(left->get(a,b), right->get(a,b));
  }

  void update(int a, int b, ll nv) {
    propagate();
    if (l>b || r<a) return;
    if (l>=a && b>=r) {
      // value = nv;
      lazy += nv;
      propagate();
      return;
    }
    left->update(a,b,nv);
    right->update(a,b,nv);
    value = operation(left->value, right->value);
  }
};