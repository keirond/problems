#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	int n = max(N, M);
	vector<vector<int>> cost(n, vector<int>(n, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cost[i][j];
		}
	}

	vector<int> row(n + 1), col(n + 1);
	vector<int> assign(n + 1), way(n + 1);

	for (int i = 1; i <= n; i++) {
		assign[0] = i;
		vector<int> minv(n + 1, INT_MAX);
		vector<bool> vt(n + 1);
		int u = 0;

		do {
			vt[u] = 1;
			int v = assign[u];
			int delta = INT_MAX, w = 0;

			for (int j = 1; j <= n; j++) {
				if (!vt[j]) {
					int cur = cost[v - 1][j - 1] - row[v] - col[j];
					if (cur < minv[j]) {
						minv[j] = cur, way[j] = u;
					}
					if (minv[j] < delta) {
						delta = minv[j], w = j;
					}
				}
			}

			for (int j = 0; j <= n; j++) {
				if (vt[j]) {
					row[assign[j]] += delta, col[j] -= delta;
				} else {
					minv[j] -= delta;
				}
			}

			u = w;
		} while (assign[u]);

		do {
			int w = way[u];
			assign[u] = assign[w];
			u = w;
		} while (u);
	}

	vector<int> ans(N + 1);
	for (int j = 1; j <= M; j++) {
		ans[assign[j]] = j;
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
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