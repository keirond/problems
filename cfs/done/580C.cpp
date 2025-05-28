#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int &d : A) cin >> d;
	vector<vector<int>> adj(N);
	for (int i = 1; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		adj[X - 1].push_back(Y - 1);
		adj[Y - 1].push_back(X - 1);
	}

	vector<bool> vt(N);
	deque<pair<int, int>> dq;
	dq.push_back({0, A[0]});
	int ans = 0;
	while (!dq.empty()) {
		auto cur = dq.back();
		dq.pop_back();
		vt[cur.first] = 1;
		if (cur.second > M) continue;
		int cnt = 0;
		for (int d : adj[cur.first]) {
			if (vt[d]) continue;
			cnt++;
			int cat = 0;
			if (A[d]) cat = cur.second + A[d];
			dq.push_back({d, cat});
		}
		if (!cnt) ans++;
	}
	cout << ans << nl;
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