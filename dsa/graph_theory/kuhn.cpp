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
		adj[V].push_back(U);
	}

	vector<int> vt(N), match(N, -1);

	function<bool(int)> call = [&](int u) {
		if (vt[u]) return 0;
		vt[u] = 1;
		for (int v : adj[u]) {
			if (match[v] == -1 || call(match[v])) {
				match[v] = u;
				return 1;
			}
		}
		return 0;
	};

	for (int i = 0; i < N; i++) {
		vt.assign(N, 0);
		call(i);
	}

	for (int i = 0; i < N; i++) {
		if (match[i] == -1) {
			cout << match[i] + 1 << ' ' << i + 1 << nl;
		}
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