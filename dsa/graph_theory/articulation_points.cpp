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

	int idx = 0;
	vector<int> disc(N, -1), lowlink(N, -1);

	vector<int> points;
	function<void(int, int)> call =
		[&](int u, int p) {
			int child = 0;
			disc[u] = lowlink[u] = idx++;

			for (int v : adj[u]) {
				if (disc[v] == -1) {
					call(v, u);
					lowlink[u] = min(lowlink[u], lowlink[v]);
					if (disc[u] <= lowlink[v] && p != -1) {
						points.push_back(u);
					}
					child++;
				} else
					(v != p) { lowlink[u] = min(lowlink[u], disc[v]); }
			}

			if (p == -1 && child > 1) {
				points.push_back(u);
			}
		}

	for (int i = 0; i < N; i++) {
		if (disc[i] == -1) call(i, -1);
	}

	for (int i = 0; i < points.size(); i++) {
		cout << points[i] << ' ';
	}
	cout << nl;
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