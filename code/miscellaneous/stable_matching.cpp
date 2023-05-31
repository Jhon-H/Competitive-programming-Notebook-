#include "template.h";

const int N = 1e4;

bool wPreferMOverM1(int prefer[2*N][N], int woman, int man, int man1) {
  for(int i=0; i<N; ++i) {
    if(prefer[woman][i] == man) return true;
    if(prefer[woman][i] == man1) return false;
  }
  return false; // No llega nunca
}

void stableMarriage(int prefer[2*N][N]) {
  int womanPartner[N]; // womanParttner[i] --> the partner assigned to woman N+i
  bool manFree[N]; // manFree[i] --> if false --> man is free

  memset(womanPartner, -1, sizeof womanPartner);  
  memset(manFree, true, sizeof manFree);  
  
  int freeCount = N;
  while(freeCount > 0) {
    int man;
    for(man = 0; man < N; man++) {
      if(manFree[man]) break;
    }

    for(int i=0; i<N && manFree[man]; ++i) {
      int woman = prefer[man][i];

      if(womanPartner[woman-N] == -1) {
        womanPartner[woman-N] = man;
        manFree[man] = false;
        freeCount--;
      } else {
        int man1 = womanPartner[woman-N];

        if(wPreferMOverM1(prefer, woman, man, man1)) {
          womanPartner[woman-N] = man;
          manFree[man] = false;
          manFree[man1] = true;
        }
      }
    }
  }

  // answer in womanPartner (woman i+N --> womanParter[i])
  for(int i=0; i<N; ++i) {
    cout << "Woman: " << i+N << " with Man: " << womanPartner[i] << endl; 
  }
}
