#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	// square matrix size: Hungarian Alg needs nxn cost matrix
	int n = max(N, M);
	vector<vector<int>> cost(n, vector<int>(n, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cost[i][j];
		}
	}

	// row[i] & col[j] are dual vairables (potentials)
	vector<int> row(n + 1), col(n + 1);

	// assign[j]: the worker assigned to job j
	// way[j]: the previous column used to reach column j
	vector<int> assign(n + 1), way(n + 1);

	for (int i = 1; i <= n; i++) {
		assign[0] = i; // start augmenting from row i
		vector<int> minv(n + 1, INT_MAX); // minv[j] = min slack value for column j
		vector<bool> vt(n + 1); // visited flags for columns
		int u = 0; // column to expand from

		do {
			vt[u] = 1;
			int v = assign[u]; // current row to expand from
			int delta = INT_MAX, w = 0; // delta = min slack, w = column to update next;

			// try to relax the assignment to all unvisited columns
			for (int j = 1; j <= n; j++) {
				if (!vt[j]) {
					// reduced cost = cost - dual variables
					int cur = cost[v - 1][j - 1] - row[v] - col[j];
					if (cur < minv[j]) {
						minv[j] = cur, way[j] = u; // remember the previous column
					}
					if (minv[j] < delta) {
						delta = minv[j], w = j;
					}
				}
			}

			// update potentials (dual variables) to maintain reduced costs
			for (int j = 0; j <= n; j++) {
				if (vt[j]) {
					row[assign[j]] += delta, col[j] -= delta;
				} else {
					minv[j] -= delta;
				}
			}

			u = w; /// move to the column with smallest clack
		} while (assign[u]); // continue until we find an unmatched column

		// reconstruct the augmenting path and update matching
		do {
			int w = way[u];
			assign[u] = assign[w];
			u = w;
		} while (u);
	}

	// construct final assignment result
	// ans[i] = j means row i assigned to column j
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