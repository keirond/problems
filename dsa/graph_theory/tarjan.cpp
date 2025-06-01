#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

int ti = 0, cnt = 0;
vector<vector<int>> adj, scc;
vector<int> low, disc;
deque<int> stk;
vector<bool> in_stk;

void dfs(int u) {
	disc[u] = low[u] = ti++;
	stk.pb(u);
	in_stk[u] = 1;

	for (int v : adj[u]) {
		if (disc[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (in_stk[v]) {
			low[u] = min(low[u], disc[v]);
		}
	}

	if (low[u] == disc[u]) {
		vector<int> temp;
		while (1) {
			int v = stk.back();
			stk.pop_back();
			in_stk[v] = 0;
			temp.push_back(v);
			if (v == u) break;
		}
		scc.pb(temp);
		cnt++;
	}
}

void tarjan(int V) {
	for (int u = 0; u < V; u++) {
		if (disc[u] == -1) {
			dfs(u);
		}
	}
}

void solve(int test_case [[maybe_unused]]) {
	int V, E;
	cin >> V >> E;

	adj.resize(V);
	while (E--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	disc.assign(V, -1);
	low.resize(V);
	in_stk.resize(V);
	tarjan(V);

	cout << cnt << nl;
	for (int i = cnt - 1; i >= 0; i--) {
		auto &d = scc[i];
		cout << d.size();
		for (int e : d) cout << ' ' << e;
		cout << nl;
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************