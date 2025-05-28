#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int X0, Y0, X1, Y1;
	cin >> X0 >> Y0 >> X1 >> Y1;
	int N;
	cin >> N;
	unordered_map<int, vector<pair<int, int>>> mp;
	for (int i = 0; i < N; i++) {
		int R, A, B;
		cin >> R >> A >> B;
		mp[R].push_back({A, B});
	}

	unordered_map<int, unordered_set<int>> vt;
	vector<pair<int, int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
										{0, 1},	  {1, -1}, {1, 0},	{1, 1}};

	int ans = INT_MAX;
	deque<vector<int>> dq;
	dq.push_back({X0, Y0, 0});
	while (!dq.empty()) {
		auto cur = dq.front();
		int x = cur[0], y = cur[1], d = cur[2];
		dq.pop_front();
		if (vt[x].contains(y)) continue;
		if (x == X1 && y == Y1) {
			ans = min(ans, d);
		}
		vt[x].insert(y);
		for (auto e : direction) {
			int nx = x + e.first, ny = y + e.second;
			bool allowed = false;
			if (mp.contains(nx)) {
				for (auto f : mp[nx]) {
					if (f.first <= ny && ny <= f.second) {
						allowed = true;
						break;
					}
				}
			}
			if (allowed) dq.push_back({nx, ny, d + 1});
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << nl;
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