#include "template.h";
// find all shortest path
// O(n^3)
// Trick: orden correcto es KIJ, sino esta seguro, ejecute floydwarshall 3 veces

// Detectar ciclo negativo:
// Si al final del algoritmo la distance de un nodo x a si mismo
// es negativa, entonces **hay** ciclo negativo
vector<vector<int>> dist, adj, parent;
void init(int n) {
  dist = vector<vector<int>>(n+1, vector<int>(n+1, 0));
  parent = vector<vector<int>>(n+1, vector<int>(n+1, 0));

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      parent[i][j] = i;
    }
  }

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(i == j) dist[i][j] = 0;
      else if(adj[i][j]) dist[i][j] = adj[i][j];
      else dist[i][j] = INF;  
    }
  }
}

void floydwarshall(int n) {
  for(int k=1; k<=n; ++k) {
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        if (dist[i][k] < INF && dist[k][j] < INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          parent[i][j] = parent[k][j];
        }
      }
    }
  }
}

void printPath(int i, int j) {
  if(i != j) printPath(i, parent[i][j]);
}