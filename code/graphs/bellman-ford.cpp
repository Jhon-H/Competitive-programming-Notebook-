#include "template.h";

// find shortest distance from a node x to all other nodes
// O(E*V) list adjacency, O(V^3) matrix
// trick: si no se modifica ninguna distancia durante una ronda, detenga el algoritmo

// Detectar ciclos negativos: 
// Ejecutar el algoritmo n veces, si en la ultima vez se modifica alguna distancia
// entonces **hay** un ciclo negativo
struct EDGE { int a, b, w; };
vector<int> dist;
vector<EDGE> edges;

void bellmanFord(int x, int n) {
  dist.resize(n+1, INF);
  dist[x] = 0;

  for(int i=1; i<=n-1; ++i) {
    for(auto e: edges) {
      int a = e.a, b = e.b, w = e.w;
      dist[b] = min(dist[b], dist[a]+w); // cuidado con overflow !!!!
    }
  }

  bool negativeCycle = false;
  for(auto e: edges) {
    int a = e.a, b = e.b, w = e.w;
    if(dist[b] > dist[a]+w) negativeCycle = true;
  }
}
