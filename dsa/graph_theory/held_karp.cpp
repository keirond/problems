#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;
	vector<vector<int>> dist(n, vector<int>(n));
	int sz = 1 << n;
	vector<vector<int>> dp(sz, vector<int>(n, INT_MAX));
	dp[1][0];

	for (int mask = 1; mask < sz; mask++) {
		for (int u = 0; u < n; u++) {
			if (!mask & (1 << u)) continue;
			for (int v = 0; v < n; v++) {
				if (u == v || !mask & (1 << v)) continue;
				dp[mask][u] =
					min(dp[mask][u], dp[mask ^ (1 << u)][v] + dist[v][u]);
			}
		}
	}

	int ans = INT_MAX;
	for (int u = 1; u < n; u++) {
		ans = min(ans, dp[sz - 1][u] + dist[u][0]);
	}
	cout << ans << nl;
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