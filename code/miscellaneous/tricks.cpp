// log base 2 of 32 bit integer
int log2(int x) {
  int res = 0;
  while (x >>= 1) res++;
  return res;
}

// is power of 2
bool isPowerof2(int x) {
  return (x && !(x & x-1));
}

// Most significative digit
int MSD(int n) {
  if(n == 0) return 0;
  
  int k = log10(n);
  int x = pow(10,k);
  int ans = n/x;

  return ans;
}

// Number of digits
int NOF (int n) {
  return floor(log10(n)) + 1;
}

// Perfect square
bool isPerfectSquare(int x) {
  int s = sqrt(x);
  return (s * s == x);
}

// Use C++11 inbuilt algorithms
all_of(first, first+n, ispositive()); 
any_of(first, first+n, ispositive());
none_of(first, first+n, ispositive());

// Fast multiplication or division by 2
n = n << 1 // Mutiply
n = n >> 1 // Divide

// Custom comparator sort

// Notes:
// 1. Use emplace_back() instead push_back()
