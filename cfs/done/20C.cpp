#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

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
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (vt[u]) continue;
		vt[u] = 1;
		for (auto [v, w] : adj[u]) {
			if (!vt[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				prev[v] = u;
				pq.emplace(dist[v], v);
			}
		}
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