#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<vector<ll>> dist(N, vector<ll>(N, INT_MAX));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}

	vector<int> order(N);
	for (int &d : order) {
		cin >> d;
		d--;
	}

	vector<ll> ans(N);
	for (int k = N - 2; k >= 0; k--) {
		int l = order[k];
		for (int i = k + 1; i < N; i++) {
			int m = order[i];
			for (int j = k + 1; j < N; j++) {
				int r = order[j];
				dist[l][r] = min(dist[l][r], dist[l][m] + dist[m][r]);
				dist[r][l] = min(dist[r][l], dist[r][m] + dist[m][l]);
			}
		}
		for (int j = k + 1; j < N; j++) {
			int r = order[j];
			ans[k] += dist[l][r];
			ans[k] += dist[r][l];
		}

		for (int i = k + 1; i < N; i++) {
			int m = order[i];
			for (int j = k + 1; j < N; j++) {
				int r = order[j];
				dist[m][r] = min(dist[m][r], dist[m][l] + dist[l][r]);
				ans[k] += dist[m][r];
			}
		}
	}

	for (int i = 0; i < N; i++) cout << ans[i] << ' ';
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