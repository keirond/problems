#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

int MD = 20;

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N), dp(N, vector<int>(MD));
	for (int i = 0; i < N - 1; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<int> depth(N), vt(N);
	deque<int> dq;
	dq.push_back(0);
	while (!dq.empty()) {
		int u = dq.front();
		dq.pop_front();
		vt[u] = 1;
		for (int v : adj[u]) {
			if (!vt[v]) {
				dq.push_back(v);
				depth[v] = depth[u] + 1;
				dp[v][0] = u;
			}
		}
	}

	for (int j = 1; j < MD; j++) {
		for (int i = 0; i < N; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	auto is_ancestor = [&](int u, int v) -> bool {
		if (depth[u] > depth[v]) return false;
		int dif = depth[v] - depth[u];
		for (int i = 0; i < MD; i++) {
			if (dif & 1 << i) v = dp[v][i];
		}
		return u == v;
	};

	while (M--) {
		int K;
		cin >> K;
		vector<int> nodes(K);
		int deepest = 0;
		for (int &d : nodes) {
			cin >> d;
			d--;
			if (depth[d] > depth[deepest]) {
				deepest = d;
			}
		}

		bool ok = true;
		for (int i = 0; i < K; i++) {
			if (!is_ancestor(dp[nodes[i]][0], deepest)) ok = false;
		}
		cout << (ok ? "YES" : "NO") << nl;
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