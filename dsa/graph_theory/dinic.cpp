#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cap(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		cap[u][v] = w;
	}

	int s, t;
	cin >> s >> t;

	vector<int> level;
	vector<bool> vt;

	function<bool()> bfs = [&]() {
		level.assign(n, -1);
		deque<int> dq;
		dq.push_back(s);
		while (!dq.empty()) {
			int u = dq.front();
			dq.pop_front();
			for (int v = 0; v < n; v++) {
				if (cap[u][v] && level[v] == -1) {
					level[v] = level[u] + 1;
				}
			}
		}

		return level[t] != -1;
	};

	function<int(int, int)> dfs = [&](int u, int pushed) {
		if (u == t) return pushed;
		for (int v = 0; v < n; v++) {
			if (cap[u][v] && level[v] == level[u] + 1) {
				int tr = dfs(v, min(pushed, cap[u][v]));
				if (t > 0) {
					cap[u][v] -= tr;
					return tr;
				}
			}
		}
		return 0;
	};

	ll flow = 0;
	while (bfs()) {
		vt.assign(n, false);
		while (int pushed = dfs(s, INT_MAX)) {
			flow += pushed;
		}
	}
	cout << flow << nl;

	// Minimum Cut
	vt.assign(n, false);
	deque<int> dq;
	dq.push_back(s);
	vt[s] = 1;
	while (!dq.empty()) {
		int u = dq.front();
		dq.pop_front();
		for (int v = 0; v < n; v++) {
			if (cap[u][v] > 0 && !vt[v]) {
				vt[v] = 1;
				dq.push_back(v);
			}
		}
	}

	for (int u = 0; u < n; u++) {
		if (!vt[u]) continue;
		for (int v = 0; v < n; v++) {
			if (!vt[u] && cap[u][v] == 0) {
				cout << u + 1 << ' ' << v + 1 << nl;
			}
		}
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