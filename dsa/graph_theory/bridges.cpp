#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
	}

	int idx = 0;
	vector<int> disc(N, -1), lowlink(N, -1);

	vector<pair<int, int>> bridges;
	function<void(int, int)> call = [&](int u, int p) {
		disc[u] = lowlink[u] = idx++;
		for (int v : adj[u]) {
			if (disc[v] == -1) {
				call(v, u);
				lowlink[u] = min(lowlink[u], lowlink[v]);
				if (disc[u] < lowlink[v]) {
					bridges.push_back({u, v});
				}
			} else if (v != p) {
				lowlink[u] = min(lowlink[u], disc[v]);
			}
		}
	};

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) call(i, -1);
	}

	for (auto &d : bridges) {
		cout << d.first << ' ' << d.second << nl;
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************