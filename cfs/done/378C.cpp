#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M, K;
	cin >> N >> M >> K;

	int s = 0;
	vector<vector<int>> grid(N, vector<int>(M));
	deque<pair<int, int>> dq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char C;
			cin >> C;
			if (C == '.') {
				if (!s++) dq.push_back({i, j});
				grid[i][j] = 0;
			} else
				grid[i][j] = 1;
		}
	}

	int l = s - K;
	while (!dq.empty() && l > 0) {
		auto cur = dq.back();
		dq.pop_back();
		int i = cur.first, j = cur.second;
		if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != 0) continue;
		grid[i][j] = 2, l--;
		dq.push_back({i - 1, j});
		dq.push_back({i, j - 1});
		dq.push_back({i + 1, j});
		dq.push_back({i, j + 1});
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0)
				cout << 'X';
			else if (grid[i][j] == 1)
				cout << '#';
			else
				cout << '.';
		}
		cout << nl;
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