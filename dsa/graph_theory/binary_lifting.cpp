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

vector<vector<int>> adj;
vector<int> depth;

void dfs(int i) {

}

int lca(int u, int v) {}

void solve(int test_case [[maybe_unused]]) {
	int N, P;
	cin >> N >> P;
	adj.resize(N);
	depth.resize(N);
	while (P--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int Q;
	cin >> Q;
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