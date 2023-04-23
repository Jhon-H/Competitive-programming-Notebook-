#include "template.h";

struct Edge {
  int u, v;
  ll cap, flow = 0;
  Edge(int u_, int v_, ll cap_) {
    u = u_;
    v = v_;
    cap = cap_;
  }
};

struct Dinic { // O(V^2 * E)
  vector<Edge> edges;
  vector<vi> adj;
  int n, m = 0, s, t;
  vi level, ptr;
  queue<int> q;
  vi S, T; set<int> Ss;

  Dinic(int n_, int s_, int t_) {
    n = n_;
    s = s_;
    t = t_;
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void addEdge(int u, int v, ll cap, ll invCap = 0) {
    edges.pb(Edge(u, v, cap)); // index = m
    edges.pb(Edge(v, u, invCap)); // index = m + 1
    adj[u].pb(m);
    adj[v].pb(m+1);
    m += 2;
  }

  // !!Not verified: Jhon
  void gen_min_cut() {
    level.assign(n, -1);
    level[s] = 0;
    min_cut(s);

    for(int i: Ss) S.pb(i);
    
    for(int i=0; i<n; ++i) {
        if(Ss.count(i)) continue;
        T.pb(i);
    }
  }

  // !!Not verified: Jhon
  void min_cut(int u) {
    Ss.insert(u);
    if(u == t) return;

    for(int i=0; i<sz(adj[u]); ++i) {
        int id = adj[u][i];
        if(edges[id].cap - edges[id].flow > 0 && level[edges[id].v] == -1) {
            level[edges[id].v] = 0;
            min_cut(edges[id].v);
        }
    }
  }

  bool bfs() { // busque un camino de aumento de s a t
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int id: adj[u]) {
        if (edges[id].cap - edges[id].flow < 1) // arista saturada
          continue;
        if (level[edges[id].v] != -1) // ya se calculo la distancia desde s a v
          continue;
        level[edges[id].v] = level[u] + 1;
        q.push(edges[id].v);
      }
    }
    return level[t] != -1; // hay camino de s a t en G(lf) (grafo de nivel de grafo residual)
  }

  ll dfs(int u, ll pushed) { // encuentre 1 camino arbitrario de s a t
    if(pushed == 0) return 0; // No puede agregar flujo
    if(u == t) return pushed; // Llego a t, retorne la minima capacidad residual del camino
    for(int &cid = ptr[u]; cid < sz(adj[u]); cid++) { // por cada arista desde u
      // Nota: &cid es un truco, para que en siguientes consultas (cuando acabe un dfs)
      // empiece desde una arista visitada, es decir, no visite las que ya sabe que no puede
      int id = adj[u][cid]; // obtenga el id de la arista
      int v = edges[id].v; // obtenga el destino (u, v) de esa arista
      if(level[u] + 1 != level[v]) continue; // no es arista de nivel consecutivo
      if(edges[id].cap - edges[id].flow < 1) continue; // arista esta saturada
      // siga el camino desde v (u, v), lleve la capacidad residual minima del camino 
      ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
      if(tr == 0) continue; // No puede agregar flujo
      edges[id].flow += tr; // A todas las arista del camino, agregue la maxima capacida residual posible
      edges[id ^ 1].flow -= tr; // Trick: a las aristas inversas, restele el flujo
      // --> id ^ 1 = id + 1 (0^1 = 1) (2^1 = 3)
      return tr;
    }
    return 0; // No hay camino, ya esta en flujo bloqueador
  }

  ll max_flow() {
    ll flow = 0;
    while(true) {
      fill(ALL(level), -1); // no se ha calculado ninguna distancia
      level[s] = 0;
      q.push(s);
      if(!bfs()) break; // Ya no hay camino de aumento --> found max_flow
      fill(ALL(ptr), 0); // reinicie los punteros (trick pa no visitar aristas imposibles)
      while(ll pushed = dfs(s, INFL)) { // encuentre el flujo bloqueador
        flow += pushed;
      }
    }
    return flow;
  }
};
