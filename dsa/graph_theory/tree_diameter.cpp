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
	int N;
	cin >> N;  // the number of vertices

	vector<vector<int>> adj(N);
	for (int i = 1; i < N; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	int fN = 0, fDist = 0;
	vector<bool> vt(N);

	deque<pair<int, int>> dq;
	dq.push_back({0, 0});
	while (!dq.empty()) {
		auto cur = dq.back();
		dq.pop_back();
		int u = cur.first, dist = cur.second;
		if (dist > fDist) {
			fN = u;
			fDist = dist;
		}
		if (vt[u]) continue;
		vt[u] = 1;
		for (int v : adj[u]) dq.push_back({v, dist + 1});
	}

	fDist = 0;
	dq.clear(), vt.assign(N, 0);
	dq.push_back({fN, 0});
	while (!dq.empty()) {
		auto cur = dq.back();
		dq.pop_back();
		int u = cur.first, dist = cur.second;
		fDist = max(fDist, dist);
		if (vt[u]) continue;
		vt[u] = 1;
		for (int v : adj[u]) dq.push_back({v, dist + 1});
	}

	cout << fDist << nl;
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