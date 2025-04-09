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

int LOG = 20;

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> depth;

void dfs(int u, int p) {
	dp[u][0] = p;
	for (int i = 1; i < LOG; i++) {
		dp[u][i] = dp[dp[u][i - 1]][i - 1];
	}

	for (int v : adj[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
}

int lift(int u, int k) {
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			u = dp[u][i];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = lift(u, depth[u] - depth[v]);

	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

void solve(int test_case [[maybe_unused]]) {
	int N, Q;
	cin >> N >> Q;

	adj.resize(N);
	depth.resize(N);
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;
		adj[p].pb(i);
	}

	dp.assign(N, vector<int>(LOG));
	dfs(0, 0);

	while (Q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << nl;
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