//matrix ma = matrix(p+1,p+1);
const int N = 12;
long long MOD = 1000000007;

struct matrix {
  long long m[N][N], r, c;
  matrix(int r = N, int c = N, bool iden = false) : r(r), c(c) {
    memset(m, 0, sizeof m);
    if(iden)
      for(int i = 0; i < r; i++) m[i][i] = 1;
  }
  matrix operator * (const matrix &o) const {
    matrix ret(r, o.c);
    for(int i = 0; i < r; ++i)
      for(int j = 0; j < o.c; ++j) {
        long long &r = ret.m[i][j];
        for(int k = 0; k < c; ++k)
          r = (r + 1LL*m[i][k]*o.m[k][j]) % MOD;
      }
    return ret;
  }
};
matrix pows(matrix &b, long long e){
  matrix c = matrix(b.r, b.c);
  for(int i = 0;i<b.r;i++) c.m[i][i] = 1;
  while(e){
    if(e&1LL) c = c*b;
    b = b*b , e/=2;
  }
  return c;
}