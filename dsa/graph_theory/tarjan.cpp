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

vector<vector<int>> adj;
vector<int> disc, lowlink;
vector<bool> vt;
deque<int> stk;
vector<vector<int>> SCCs;
int idx = 0;

void tarjan(int u) {
	disc[u] = lowlink[u] = idx++;
	stk.push_back(u);
	vt[u] = 1;

	for (int v : adj[u]) {
		if (disc[u] == -1) {
			tarjan(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		} else if (vt[v]) {
			lowlink[u] = min(lowlink[u], disc[v]);
		}
	}

	// if u is root of SCC
	if (lowlink[u] == disc[u]) {
		vector<int> curr_scc;
		int v;
		do {
			v = stk.back();
			stk.pop_back();
			vt[v] = 0;
			curr_scc.push_back(v);
		} while (v != u);
		SCCs.push_back(curr_scc);
	}
}

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--, V--;
		adj[U].push_back(V);
		// adj[V].push_back(U);
	}

	disc.assign(N, -1);
	lowlink.assign(N, -1);
	vt.resize(N);

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) tarjan(i);
	}

	cout << SCCs.size() << nl;
	for (auto &scc : SCCs) {
		for (int node : scc) {
			cout << node << ' ';
		}
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