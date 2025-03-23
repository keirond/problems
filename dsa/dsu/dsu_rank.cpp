#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> par, rank;

	DSU(int n) {
		par.resize(n);
		rank.resize(n);
		iota(par.begin(), par.end(), 0);
	}

	int find(int i) { return (par[i] == i) ? i : (par[i] = find(par[i])); }

	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (rank[u] < rank[v]) swap(u, v);
		par[v] = u;
		rank[u] += rank[v];
		return true;
	}
};

int main() { return 1; }