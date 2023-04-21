#include "template.h";
// regresa el orden topologico lexicrograficamente menor

vector<int> indegree;

void fillIndegree(vector<pair<int, int>> &edges, int n) {
  indegree.resize(n, 0);
  for(int i=0; i<edges.size(); ++i) {
    indegree[edges[i].second]++;
  }
}

pair<vector<int>, bool> toposortKahn(int n, vector<vector<int>> &arr) {
  priority_queue<int, vector<int>, greater<int>> q;
  // queue<int> q; --> no asegura el lexicograficamente menor
  vector<int> topo;

  for(int i=0; i<n; ++i) {
    if(indegree[i] == 0) {
      q.push(i); // se puede procesar
    }
  }

  while(!q.empty()) {
    int curr = q.top(); q.pop();
    topo.push_back(curr);

    for(int adj: arr[curr]) {
      indegree[adj]--; // virutally remove curr --> adj
      if(indegree[adj] == 0) q.push(adj);
    }
  }

  bool thereAreCycle = false;
  if(topo.size() != n) thereAreCycle = true;
  return {topo, thereAreCycle};
}

//in main --> fillIndegree(edges, n);
// tambien se puede calcular el indegree con dfs