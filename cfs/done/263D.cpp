#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

int call(vector<vector<int>> &adj, unordered_map<int, int> &path, int u, int p,
		 int k) {
	int s = path.size();
	path[u] = s;
	for (int v : adj[u]) {
		if (!path.contains(v)) {
			int t = call(adj, path, v, u, k);
			if (t != -1) return t;
		} else if (v != p) {
			int t = path[v];
			if (path.size() - t > k) return t;
		}
	}
	path.erase(u);
	return -1;
}

void solve(int test_case [[maybe_unused]]) {
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	unordered_map<int, int> path;
	int i = call(adj, path, 0, -1, K);
	if (i != -1) {
		vector<int> ans(path.size());
		cout << path.size() - i << nl;
		for (auto d : path) ans[d.second] = d.first;
		for (; i < path.size(); i++) cout << ans[i] + 1 << ' ';
		cout << nl;
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