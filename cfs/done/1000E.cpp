#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	int idx = 0;
	vector<int> disc(N, -1), lowlink(N, -1);

	vector<unordered_set<int>> bridges(N);

	function<void(int, int)> call = [&](int u, int p) {
		disc[u] = lowlink[u] = idx++;
		for (int v : adj[u]) {
			if (disc[v] == -1) {
				call(v, u);
				lowlink[u] = min(lowlink[u], lowlink[v]);
				if (disc[u] < lowlink[v]) {
					bridges[u].insert(v);
					bridges[v].insert(u);
				}
			} else if (v != p) {
				lowlink[u] = min(lowlink[u], disc[v]);
			}
		}
	};

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) call(i, -1);
	}

	vector<int> depth(N), vt(N);
	int deepest = 0;

	function<void(int)> dfs = [&](int u) {
		vt[u] = 1;
		for (int v : adj[u]) {
			if (!vt[v]) {
				depth[v] = depth[u] + int(bridges[u].contains(v));
				if (depth[v] > depth[deepest]) deepest = v;
				dfs(v);
			}
		}
	};

	dfs(0);

	depth.assign(N, 0);
	vt.assign(N, 0);
	dfs(deepest);
	cout << depth[deepest] << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int test_cases = 1;
	// cin >> test_cases;
	while (test_cases--) {
		solve(test_cases);
		cout << flush;
	}
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************