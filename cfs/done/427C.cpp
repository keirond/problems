#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

vector<int> cost;
vector<vector<int>> adj;

vector<pair<int, int>> ans;
vector<int> disc, lowlink;
vector<bool> vt;
deque<int> dq;
int idx = 0;

void tarjan(int u) {
	disc[u] = lowlink[u] = idx++;
	dq.push_back(u);
	vt[u] = 1;

	for (int v : adj[u]) {
		if (disc[v] == -1) {
			tarjan(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		} else if (vt[v]) {
			lowlink[u] = min(lowlink[u], disc[v]);
		}
	}

	if (disc[u] == lowlink[u]) {
		vector<int> curr_scc;
		int v;
		do {
			v = dq.back();
			dq.pop_back();
			vt[v] = 0;
			curr_scc.push_back(cost[v]);
		} while (v != u);
		int mncost = *min_element(curr_scc.begin(), curr_scc.end());
		int count = 0;
		for (int i = 0; i < curr_scc.size(); i++) {
			count += int(mncost == curr_scc[i]);
		}

		ans.push_back({mncost, count});
	}
}

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	cost.resize(N);
	for (int &d : cost) cin >> d;

	adj.resize(N);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
	}

	disc.assign(N, -1);
	lowlink.assign(N, -1);
	vt.resize(N);

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) tarjan(i);
	}

	ll A = 0, B = 1;
	for (auto d : ans) {
		A += d.first;
		B = B * d.second % (ll)(1e9 + 7);
	}
	cout << A << ' ' << B << nl;
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