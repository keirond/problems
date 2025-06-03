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

	ll total = 0;
	vector<bool> vt(N);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		auto [w, u] = pq.top();
		pq.pop();
		if (vt[u]) continue;
		vt[u] = 1;
		total += w;
		for (auto [v, weight] : adj[u]) {
			if (!vt[v]) {
				pq.emplace(weight, v);
			}
		}
	}

	cout << total << nl;
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