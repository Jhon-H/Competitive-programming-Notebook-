#include "template.h";

vector<ll> dist;
vi p;
vector<vector<ii>> adj;
void dijkstra(int root) { //O((n + m) log m)
  int n = SZ(adj);
  dist.assign(n, INF);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  //priority_queue<EDGE, vector<EDGE>, decltype(&comp)> q(comp);

  dist[root] = 0;
  q.push({ 0, root });

  ll dv; int v;
  while(!q.empty()) {
    tie(dv, v) = q.top(); q.pop();
    if(dv != dist[v]) continue;
    for(auto u: adj[v]) {
      int to = u.first, w = u.second;
      if(dist[to] > dist[v] + w) {
        dist[to] = dist[v] + w;
        p[to] = v;
        q.push({ dist[to], to });
      }
    }
  }
}

vector<int> find_path(int from, int to, vector<int> &p) {
  vector<int> path;
  for(int v=to; v!=from; v=p[v]) path.pb(v);
  path.pb(from);
  reverse(ALL(path));
  return path;
}