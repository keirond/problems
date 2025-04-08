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

vector<int> order;
void topological_sort(int n, vector<vector<int>> prerequisites) {
	vector<int> idr(n);
	vector<vector<int>> adj(n);

	for (auto &d : prerequisites) {
		adj[d[1]].push_back(d[0]);
		idr[d[0]]++;
	}

	deque<int> dq;
	for (int i = 0; i < n; i++)
		if (!idr[i]) dq.pb(i);

	while (!dq.empty()) {
		int t = dq.front();
		dq.pop_front();
		order.push_back(t);
		for (int d : adj[t]) {
			if (!--idr[d]) dq.pb(d);
		}
	}
}

void solve(int test_case [[maybe_unused]]) {
	int N, P;
	cin >> N >> P;
	vector<vector<int>> prerequisites;
	while (P--) {
		int u, v;
		cin >> u >> v;
		prerequisites.push_back({u, v});
	}
	topological_sort(N, prerequisites);
	if (order.size() != N)
		cout << "CAN'T SORT" << nl;
	else {
		for (int d : order) cout << d << ' ';
		cout << nl;
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