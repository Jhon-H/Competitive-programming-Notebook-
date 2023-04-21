// Opcion 1
const int MX = 1817;
long long MOD = 1000000000+7;
int C[MX + 1][MX + 1];
void nCk() {
  C[0][0] = 1;
  aux[1] = 1;
  for (int n = 1; n <= MX; ++n) {
    C[n][0] = C[n][n] = 1;
      for (int k = 1; k < n; ++k) {
        C[n][k] = (C[n - 1][k - 1] % MOD + C[n - 1][k] % MOD ) % MOD;
      }
  }
}

// Opcion 3
ll fact[nax];
ll binpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % MOD, e /= 2)
		if (e & 1LL) ans = ans * b % MOD;
	return ans;
}

ll C(int n, int k){
  if(n<k) return 0;
  return (fact[n] * binpow(fact[n-k], MOD-2) %MOD) * binpow(fact[k], MOD-2)%MOD;
}
fact[0] = 1;
    for(int i=1; i<nax; ++i) fact[i] = (1LL*i*fact[i-1])%MOD;