#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> color(N);
	for (int &d : color) cin >> d;

	vector<vector<int>> adj(N);
	for (int i = 1; i < N; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<bool> vt(N);

	int fN = 0, fD = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>,
				   greater<pair<int, int>>>
		dq;
	dq.push({fD, fN});
	while (!dq.empty()) {
		auto cur = dq.top();
		dq.pop();
		int d = cur.first, u = cur.second;
		if (vt[u]) continue;
		if (d > fD) fN = u, fD = d;
		vt[u] = 1;
		for (int v : adj[u]) dq.push({d + int(color[u] != color[v]), v});
	}

	fD = 1;
	vt.assign(N, 0);
	dq.push({fD, fN});
	while (!dq.empty()) {
		auto cur = dq.top();
		dq.pop();
		int d = cur.first, u = cur.second;
		if (vt[u]) continue;
		if (d > fD) fN = u, fD = d;
		vt[u] = 1;
		for (int v : adj[u]) dq.push({d + int(color[u] != color[v]), v});
	}

	cout << fD / 2 << nl;
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