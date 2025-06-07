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

	vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
	for (int i = 0; i < N; i++) {
		dist[i][i] = 0;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (dist[i][i] < 0) {
			cout << -1 << nl;
			return;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INT_MAX) {
				cout << "INF ";
			} else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << nl;
	}
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