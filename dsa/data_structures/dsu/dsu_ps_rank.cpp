#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> par, rnk;
	stack<pair<int, int>> hst;

	DSU(int n) {
		par.resize(n);
		rnk.resize(n);
	}

	int find(int i) { return par[i] == i ? i : (par[i] = find(par[i])); }

	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (rnk[u] < rnk[v]) swap(u, v);
		par[v] = u;
		rnk[u] += rnk[v];
		return true;
	}
};

int main() { return 0; }