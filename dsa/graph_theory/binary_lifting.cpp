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

int MD = 20;

void solve(int test_case [[maybe_unused]]) {
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<vector<int>> adj(N), dp(N, vector<int>(MD));
	vector<int> depth(N);
	adj.resize(N);
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		dp[V][0] = U;
	}

	deque<pair<int, int>> dq;
	dq.push_back({0, 0});
	while (!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();
		depth[cur.first] = cur.second;
		for (int v : adj[cur.first]) {
			dq.push_back({v, cur.second + 1});
		}
	}

	for (int i = 1; i < MD; i++) {
		for (int j = 0; j < N; j++) {
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}

	while (Q--) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		if (depth[U] < depth[V]) swap(U, V);
		int dif = depth[U] - depth[V];
		for (int i = 0; i < MD; i++) {
			if (dif & 1 << i) U = dp[U][i];
		}

		if (U == V) {
			cout << U + 1 << nl;
			continue;
		}
		for (int i = MD - 1; i >= 0; i--) {
			if (dp[U][i] != dp[V][i]) {
				U = dp[U][i];
				V = dp[V][i];
			}
		}
		cout << dp[U][0] + 1 << nl;
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