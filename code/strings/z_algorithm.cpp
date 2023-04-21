#include "template.h";

vi z_algo(string &s) { // O(|S|)
  int n = SZ(s), l=0, r=0;
  vi z(n, 0); 
  for(int i=1; i<n; ++i) {
    if(i < r) z[i] = min(r-i, z[i-l]);
    while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if(z[i]+i > r) { l = i; r = z[i]+i; }
  }
  return z;
}