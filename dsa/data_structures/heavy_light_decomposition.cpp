#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

int timer = 0;
vector<int> values;
vector<vector<int>> adj;
vector<int> sz, par, dep, heavy;
vector<int> in, out, head, flat;

void add_edge(int u, int v);
void dfs(int u, int p) {
	sz[u] = 1;
	par[u] = p;
	if (p == -1)
		dep[u] = 1;
	else
		dep[u] = dep[p] + 1;
	int max_sz = 0;
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

void decompose(int u, int h) {
	in[u] = ++timer;
	flat[timer] = values[u];
	head[u] = h;

	if (heavy[u] != -1) {
		decompose(heavy[u], h);
	}

	for (int v : adj[u]) {
		if (v != par[u] && v != heavy[u]) {
			decompose(v, v);
		}
	}

	out[u] = timer;
}

vector<int> st;

void build(int node = 1, int l = 1, int r = timer) {
	if (l == r) {
		st[node] = flat[l];
		return;
	}
	int m = l + (r - l >> 1);
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	st[node] = st[node << 1] + st[node << 1 | 1];
}

void update(int x, int val, int node = 0, int l = 1, int r = timer) {
	if (l == r) {
		st[node] = val;
		return;
	}
	int m = l + (r - l >> 1);
	if (x < m)
		update(x, val, node << 1, l, m);
	else
		update(x, val, node << 1 | 1, m + 1, r);
	st[node] = st[node << 1] + st[node << 1 | 1];
}

int query(int ql, int qr, int node = 1, int l = 1, int r = timer) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && r <= qr) return st[node];
	int m = l + (r - l >> 1);
	return query(ql, qr, node << 1, l, m) +
		   query(ql, qr, node << 1 | 1, m + 1, r);
}

int path_query(int u, int v) {
	int ans = 0;
	while (head[u] != head[v]) {
		if (dep[head[u]] < dep[head[v]]) swap(u, v);
		ans += query(in[head[u]], in[u]);
		u = par[head[u]];
	}

	if (dep[u] > dep[v]) swap(u, v);
	ans += query(in[u], in[v]);
	return ans;
}

int subtree_query(int u) { return query(in[u], out[u]); }

void solve(int test_case [[maybe_unused]]) {
	int n, q;
	cin >> n >> q;

	values.assign(n, 0);
	adj.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	sz.assign(n, 0);
	par.assign(n, -1);
	dep.assign(n, 0);
	heavy.assign(n, -1);

	dfs(0, -1);

	in.assign(n, -1);
	out.assign(n, -1);
	head.assign(n, -1);
	flat.assign(n, 0);

	decompose(0, 0);

	st.assign(4 * n, 0);

	build();

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
			u--;
			cout << subtree_query(u) << nl;
		} else if (op == 3) {
			int u, val;
			cin >> u >> val;
			u--;
			update(in[u], val);
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