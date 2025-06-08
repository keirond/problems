#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	unordered_set<int> primes;
	for (int &d : nums) {
		cin >> d;
		int t = d;
		for (int i = 2; (ll)i * i <= t; i++) {
			if (t % i == 0) {
				primes.insert(i);
				while (t % i == 0) {
					t /= i;
				}
			}
		}
		if (t > 1) {
			primes.insert(t);
		}
	}

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u % 2 == 0) swap(u, v);
		adj[u].push_back(v);
	}

	vector<vector<int>> cap;
	vector<int> level;

	function<bool()> bfs = [&]() {
		level.assign(n + 2, -1);
		level[0] = 0;
		deque<int> dq;
		dq.push_back(0);
		while (!dq.empty()) {
			int u = dq.front();
			dq.pop_front();
			for (int v = 0; v < n + 2; v++) {
				if (cap[u][v] && level[v] == -1) {
					level[v] = level[u] + 1;
					dq.push_back(v);
				}
			}
		}
		return level[n + 1] != -1;
	};

	function<int(int, int)> dfs = [&](int u, int pushed) {
		if (u == n + 1) return pushed;
		for (int v = 0; v < n + 2; v++) {
			if (cap[u][v] && level[v] == level[u] + 1) {
				int tr = dfs(v, min(pushed, cap[u][v]));
				if (tr) {
					cap[u][v] -= tr;
					cap[v][u] += tr;
					return tr;
				}
			}
		}
		return 0;
	};

	function<int(int)> call = [&](int p) {
		cap.assign(n + 2, vector<int>(n + 2, 0));
		for (int u = 1; u <= n; u++) {
			for (int v : adj[u]) {
				cap[u][v] = INT_MAX;
			}
		}
		for (int i = 1; i <= n; i++) {
			int t = nums[i - 1];
			while (t % p == 0) {
				t /= p;
				if (i % 2)
					cap[0][i]++;
				else
					cap[i][n + 1]++;
			}
		}

		int flow = 0;
		while (bfs()) {
			while (int pushed = dfs(0, INT_MAX)) {
				flow += pushed;
			}
		}
		return flow;
	};

	ll flow = 0;
	for (int p : primes) flow += call(p);
	cout << flow << nl;
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