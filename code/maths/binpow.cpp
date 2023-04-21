// O(log n)
// if m if prime, use a^(n mod (m-1)) instead a^n
long long binpow(long long a, long long b, long long m  = 1) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
