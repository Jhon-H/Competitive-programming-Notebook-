#include "template.h";

struct EdmondsKarp { // O(V*E^2)
  int n, s, t;
  vector<vl> capacity, flow;
  vector<vi> adj;
  vi parent;

  EdmondsKarp(int N) {
    n = N;
    adj.resize(n);
    capacity = flow = vector<vl>(n, vl(n, 0));
  }

  void addEdge(int u, int v, ll c) {
    capacity[u][v] = c;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int bfs(int s, int t) {
    queue<pil> q;
    parent.assign(n, -1);
    parent[s] = -2;
    q.push({ s, INFL });

    while(!q.empty()) {
      int curr = q.front().fi;
      ll currFlow = q.front().se;
      q.pop();

      for(int next: adj[curr]) {
        if(parent[next] == -1 && capacity[curr][next] - flow[curr][next] > 0) {
          parent[next] = curr;
          ll new_flow = min(currFlow, capacity[curr][next] - flow[curr][next]);
          if(next == t) return new_flow;
          q.push({ next, new_flow });
        }
      }
    }

    return 0;
  }

  ll max_flow(int s, int t) {
    ll maxFlow = 0, new_flow = 0;

    while(new_flow = bfs(s, t)) {
      maxFlow += new_flow;
      int curr = t;
      while(curr !=  s) {
        int p = parent[curr];
        flow[p][curr] += new_flow;
        flow[curr][p] -= new_flow;
        curr = p;
      }
    }

    return maxFlow;
  }
};
