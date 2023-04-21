#include "template.h";

vi get_phi(string &s) { // O(|s|)
  int n = SZ(s);
  vi phi(n, 0); // proper suffix - preffix [0 ... i]
  for(int i=1, j=0; i<n; ++i) {
      while(j > 0 && s[i] != s[j]) j = phi[j-1];
      if(s[i] == s[j]) j++;
      phi[i] = j;
  }
  return phi;
}

void kmp(string &t, string &p){ // O(|t| + |p|)
  vi phi = get_phi(p);
  int matches = 0;
  for(int i = 0, j = 0; i < SZ(t); ++i ) {
    while(j > 0 && t[i] != p[j] ) j = phi[j-1];
    if(t[i] == p[j]) ++j;
    if(j == SZ(p)) {
      matches++;
      j = phi[j-1];
    }
  }
}