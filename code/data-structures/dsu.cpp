#include <bits/stdc++.h>
using namespace std;

// Trick
// - Cada nodo guarda -1 como flag inicial
// Cada hijo va a guardar el indice de su padre
// Cada padre-maximo (root del grupo) va a tener el tamano del grupo. pero en negativo
//  asi, cuando se encuentre un valor negativo es porque estamos frente a un root, y al multiplicarlo por
//  -1 obtenemos el tamano del grupo

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	//* get representive component (uses path compression)
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

	bool isSameSet(int a, int b) { return find(a) == find(b); }

	int getSize(int x) { return -e[find(x)]; }

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y); //* Union by size (by rank)
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

