#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

//O((n + m) log m)
const int INF = 1e9;
vector<int> dist, p;
vector<vector<pair<int, int>>> adj;
void dijkstra(int root) {
  int n = adj.size();
  dist.assign(n, INF);
  p.assign(n, -1);
  priority_queue<pair<int, int>, vector<ii>, greater<ii>> q;

  dist[root] = 0;
  q.push({ 0, root });

  while(!q.empty()) {
    int dv = q.top().first, v = q.top().second; q.pop();
      if(dv != dist[v]) continue;
    for(auto u: adj[v]) {
      int to = u.first;
      int w = u.second;
      if(dist[to] >= dist[v] + w) {
        dist[to] = dist[v] + w;
        p[to] = v;
        q.push({ dist[to], to });
      }
    }
  }
}

vector<int> find_path(int from, int to, vector<int> &p) {
  vector<int> path;
  for(int v=to; v!=from; v=p[v]) {
    path.push_back(v);
  }
  path.push_back(from);
  reverse(ALL(path));
  return path;
}