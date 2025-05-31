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
	int N, Q;
	cin >> N >> Q;

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

	while (Q--) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		if (depth[U] < depth[V]) swap(U, V);
		int dif = depth[U] - depth[V];
		for (int i = 0; i < MD; i++) {
			if (dif & 1 << i) U = dp[U][i];
		}

		if (U != V) {
			for (int i = MD - 1; i >= 0; i--) {
				if (dp[U][i] != dp[V][i]) {
					U = dp[U][i];
					V = dp[V][i];
				}
			}
			U = dp[U][0];
		}
		cout << U + 1 << nl;
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