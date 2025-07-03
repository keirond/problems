#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

bool call(int u, int p, vector<vector<int>> &adj, vector<int> &ans,
		  vector<int> &vt) {
	vt[u] = 1;
	ans.push_back(u);
	for (int v : adj[u]) {
		if (!vt[v])
			if (call(v, u, adj, ans, vt))
				return true;
			else if (v != p) {
				ans.push_back(v);
				return true;
			}
	}
	ans.pop_back();
	return false;
}

void solve(int test_case [[maybe_unused]]) {
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	vector<int> ans, vt(N);
	if (call(0, -1, adj, ans, vt)) {
		int lst = ans.back();
		int i = 0;
		while (i < ans.size() && ans[i] != lst) i++;
		cout << ans.size() - ++i << nl;
		for (; i < ans.size(); i++) {
			cout << ans[i] << ' ';
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