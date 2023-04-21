#include "template.h";

// Use for dense graph --> m = n^2
vector<int> dist, p;
vector<vector<pair<int, int>>> adj;
void dijkstra(int root) { // O(n^2 + m)
  int n = 0; // adj
  dist.assign(n, INF);
  p.assign(n, -1);
  vector<bool> u(n, false);

  dist[root] = 0;
  for(int i=0; i<n; ++i) {
    int v = -1;
    for(int j=0; j<n; ++j) {
      if(!u[j] && (v == -1 || dist[j] < dist[v])) {
        v = j;
      }
    }

    if(dist[v] == INF) break;

    u[v] = true;
    for(auto e: adj[v]) {
      int to = e.first;
      int len  = e.second;

      if(dist[to] > dist[v] + len) {
        dist[to] = dist[v] + len;
        p[to] = v;
      }
    }
  }
}

vector<int> get_path(int from, int to, vector<int> &p) {
  vector<int> path;
  for(int v=to; v!=from; v=p[v]) {
    path.push_back(v);
  }
  path.push_back(from);
  reverse(ALL(path));
  return path;
}