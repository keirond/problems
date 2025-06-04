#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<bool>> map(N, vector<bool>(M)), vt(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '.') map[i][j] = 1;
		}
	}

	function<ll(int, int, vector<pii> &)> dfs = [&](int x, int y,
													vector<pii> &stk) -> ll {
		if (x < 0 || x >= N || y < 0 || y >= M) return 0;
		if (map[x][y] == 0) return 1;
		if (vt[x][y]) return 0;
		vt[x][y] = 1;
		stk.push_back({x, y});
		return dfs(x - 1, y, stk) + dfs(x + 1, y, stk) + dfs(x, y - 1, stk) +
			   dfs(x, y + 1, stk);
	};

	vector<vector<int>> ans(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				vector<pii> stk;
				ll t = dfs(i, j, stk);
				for (auto [x, y] : stk) ans[x][y] = t;
			}
		}
	}

	while (K--) {
		int X, Y;
		cin >> X >> Y;
		X--, Y--;
		cout << ans[X][Y] << nl;
	}
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