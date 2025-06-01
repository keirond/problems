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
	int bridge = 0;

	function<void(int, int)> tarjan = [&](int u, int p) {
		disc[u] = lowlink[u] = idx++;

		for (int v : adj[u]) {
			if (disc[v] == -1) {
				tarjan(v, u);
				lowlink[u] = min(lowlink[u], lowlink[v]);
				if (disc[u] < lowlink[v]) {
					bridge++;
				}
			} else if (v != p) {
				lowlink[u] = min(lowlink[u], disc[v]);
			}
		}
	};

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) tarjan(i, -1);
	}

	if (bridge)
		cout << 0 << nl;
	else {
		vector<unordered_set<int>> ans(N);
		vector<bool> vt(N);
		function<void(int)> dfs = [&](int u) {
			vt[u] = 1;
			for (int v : adj[u]) {
				if (!vt[v]) {
					ans[u].insert(v);
					cout << u + 1 << ' ' << v + 1 << nl;
					dfs(v);
				} else if (!ans[v].contains(u)) {
					ans[u].insert(v);
					cout << u + 1 << ' ' << v + 1 << nl;
				}
			}
		};
		for (int i = 0; i < N; i++) {
			if (!vt[i]) dfs(i);
		}
	}
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