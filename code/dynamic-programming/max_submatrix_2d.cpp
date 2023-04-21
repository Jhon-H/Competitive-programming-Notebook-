#include "template.h";

//O(n^2)
// max matriz zeros, ponga todos los demas en negativo y encuentre el de suma maxima
// que debe ser 0
int maxSubRect = -127*100*100; // the lowest possible value for this problem
for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) { // start coordinate
  for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
    subRect = A[k][l]; // sum of all items from (0, 0) to (k, l): O(1)
    if (i > 0) subRect -= A[i - 1][l]; // O(1)
    if (j > 0) subRect -= A[k][j - 1]; // O(1)
    if (i > 0 && j > 0) subRect += A[i - 1][j - 1]; // O(1)
    maxSubRect = max(maxSubRect, subRect); // the answer is here
  } 
}
