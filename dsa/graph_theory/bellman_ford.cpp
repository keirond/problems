#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;
	vector<vector<pii>> adj(N);
	for (int i = 0; i < M; i++) {
		int U, V, W;
		cin >> U >> V >> W;
		U--, V--;
		adj[U].push_back({V, W});
		adj[V].push_back({U, W});
	}

	vector<int> dist(N, INT_MAX), prev(N, -1);
	vector<bool> vt(N);
	dist[0] = 0;

	for(int i=0; i<N-1; i++) {
		for()
	}

	if (dist[N - 1] == INT_MAX) {
		cout << -1 << nl;
		return;
	}

	vector<int> ans;
	for (int u = N - 1; u != -1; u = prev[u]) ans.push_back(u + 1);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
	cout << nl;
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