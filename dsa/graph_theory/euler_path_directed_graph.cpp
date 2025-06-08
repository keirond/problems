#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adj(n);
	vector<int> deg_in(n), deg_out(n);
	vector<bool> edges(m);
	int idx = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back({v, idx});
		deg_out[u]++, deg_in[v]++;
		idx++;
	}

	int odd = 0, start = 0;
	for (int i = 0; i < n; i++) {
		if (deg_in[i] != deg_out[i]) {
			odd++;
			start = i;
		}
	}

	if (odd != 0 && odd != 2) {
		cout << "NO" << nl;
		return;
	}

	vector<bool> vt(n);
	vector<int> path;
	function<void(int)> dfs = [&](int u) {
		while (!adj[u].empty()) {
			auto [v, id] = adj[u].back();
			adj[u].pop_back();
			if (edges[id]) continue;
			edges[id] = 1;
			dfs(v);
		}
		path.push_back(u);
	};

	dfs(start);
	if (path.size() >= m + 1) {
		for (int u : path) cout << u + 1 << ' ';
		cout << nl;
	} else {
		cout << "NO" << nl;
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