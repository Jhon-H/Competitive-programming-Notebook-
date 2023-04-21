#include "template.h";

// Using pascal triangle
const int MX = 1000;
long long MD = 999999937;
int C[MX + 1][MX + 1];

void nCk() {
  C[0][0] = 1;
  for(int n=1; n <= MX; ++n) {
    C[n][0] = C[n][n] = 1;
    for(int k=1; k<n; ++k) {
      C[n][k] = (C[n-1][k-1] % MOD + C[n-1][k] % MOD) % MOD;
    }
  }
}