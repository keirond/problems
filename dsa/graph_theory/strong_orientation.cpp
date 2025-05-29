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
	cin >> N; // the number of vertices
	cin >> M; // the number of edges

	vector<pair<int, int>> edges;
	vector<vector<pair<int, int>>> adj;
	for(int i=0; i<M; i++) {
		// next m lines describing the edges.
		int U, V; cin >> U >> V;
		U--, V--;
		edges.push_back({U, V});
		adj[U].push_back()
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