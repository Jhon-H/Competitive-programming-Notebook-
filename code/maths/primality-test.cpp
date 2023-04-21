// O(sqrt(n))
bool isPrime(int x) {
  for (int d = 2; d * d <= x; d++) {
    if (x % d == 0) return false;
  }
  return true;
}

// O(iter * log2(n))
bool probablyPrimeFermat(int n, int iter=5) {
  if (n < 4) return n == 2 || n == 3;

  for (int i = 0; i < iter; i++) {
    int a = 2 + rand() % (n - 3);
    if (binpow(a, n - 1, n) != 1)
      return false;
  }
  return true;
}
