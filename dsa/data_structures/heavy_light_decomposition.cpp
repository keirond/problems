#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

const int N = 1e5;
vector<int> vals;
vector<vector<int>> adj;

void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

vector<int> sz, par, dep, heavy;
void dfs(int u, int p) {
	sz[u] = 1;
	par[u] = p;
	dep[u] = (p == -1 ? 0 : dep[p]) + 1;
	int max_sz = -1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > max_sz) {
			max_sz = sz[v];
			heavy[u] = v;
		}
	}
}

int idx = 0;
vector<int> disc, head;
vector<int> flat;
void decompose(int u, int p) {
	disc[u] = idx++;
	flat[idx]
}

void build();

int path_query(int u, int v) {}
int subtree_query(int u) {}
void update(int u, int val) {}

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;

	vals.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	adj.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		add_edge(u, v);
	}

	sz.assign(n, 0);
	par.assign(n, -1);
	dep.assign(n, 0);
	heavy.assign(n, 0);
	dfs(0, -1);

	disc.assign(n, -1);
	head.assign(n, -1);
	decompose(0, 0);
	build();

	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			cout << path_query(u, v) << nl;
		} else if (op == 2) {
			int u;
			cin >> u;
			cout << subtree_query(u) << nl;
		} else if (op == 3) {
			int u, val;
			cin >> u >> val;
			update(u, val);
		}
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	cout << flush;
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************