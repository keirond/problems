#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> edges(M);
	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
		edges[i] = {U, V};
	}

	vector<int> color(N, -1);
	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			color[i] = 1;
			deque<int> dq;
			dq.push_back(i);
			while (!dq.empty()) {
				int u = dq.front();
				dq.pop_front();
				for (int v : adj[u]) {
					if (color[v] == -1) {
						color[v] = color[u] ^ 1;
						dq.push_back(v);
					} else if (color[u] == color[v]) {
						cout << "NO" << nl;
						return;
					}
				}
			}
		}
	}

	cout << "YES" << nl;
	for (int i = 0; i < M; i++) {
		if (color[edges[i].first])
			cout << 1;
		else
			cout << 0;
	}
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