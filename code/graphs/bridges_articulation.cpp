typedef pair<int, int> bridge;
vector<int> graph[MAXN];
int visited[MAXN];
int dfs_low[MAXN];//El menor nodo alcanzable desde el actual
bool articulationPoints[MAXN];
vector<bridge> bridges;
int T = 0; // time
int root; //raiz del DFS spanning tree
int rootChildren;
 
//DFS para detectar los puentes y puntos de articulacion
void dfs(int node, int P){
	//P parent
	visited[node] = T;
	dfs_low[node] = T;
	T += 1;
	for(int i=0; i<graph[node].size(); i++){
		int next = graph[node][i];
		if(next == P) continue;
		if(visited[next] == -1){
			if(root == node) rootChildren++;
			dfs(next, node);
			if(dfs_low[next] >= visited[node]){
				articulationPoints[node] = true;
			}
			if(dfs_low[next] > visited[node]){
				bridges.pb(bridge(node, next));
			}
			dfs_low[node] = min(dfs_low[next], dfs_low[node]);
 
		}
		else dfs_low[node] = min(dfs_low[node], visited[next]);
	}
}

rootChildren = 0;
root = 1;
//corremos un DFS suponiendo que el grafo es conexo
//en caso contrario, correr el DFS desde cada componente del grafo usando un for
dfs(root, -1);
for(int i=0; i<bridges.size(); i++){
    cout << "Puente entre los nodos " << bridges[i].fi << " y " << bridges[i].se << endl;
}
cout << "\nEl grafo tiene los siguientes nodos como puntos de articulacion:" << endl;
for(int i=1; i<=nodes; i++){
    if(i == root) articulationPoints[i] = (rootChildren > 1);
    if(articulationPoints[i]) cout << i << " ";
}
cout << endl;
 
	return 0;


