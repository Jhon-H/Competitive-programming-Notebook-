// O(sqrt(n) / 2)
vector<long long> trial_division2(long long n) {
  vector<long long> factorization;
  while (n % 2 == 0) {
    factorization.push_back(2);
    n /= 2;
  }
  for (long long d = 3; d * d <= n; d += 2) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  if (n > 1) factorization.push_back(n);
  return factorization;
}

// Precompute primes O(sqrt(n) using linear sieve) 
vector<long long> primes; // to sqrt(n)
vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
      if (d * d > n) break;
      while (n % d == 0) {
        factorization.push_back(d);
        n /= d;
      }
    }
    if (n > 1) factorization.push_back(n);
    return factorization;
}
