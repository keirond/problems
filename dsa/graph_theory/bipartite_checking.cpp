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
	cin >> N;
	vector<vector<int>> adj(N);

	bool is_bipartite = true;
	deque<int> dq;
	vector<int> color(N, -1);
	for (int i = 0; i < N; i++) {
		if (color[i] == -1) {
			color[i] = 0;
			dq.push_back(i);
			while (!dq.empty()) {
				int u = dq.front();
				dq.pop_front();
				for (int v : adj[u]) {
					if (color[v] == -1) {
						color[u] = color[v] ^ 1;
						dq.push_back(v);
					} else {
						is_bipartite &= color[u] != color[v];
					}
				}
			}
		}
	}

	cout << (is_bipartite ? "YES" : "NO") << nl;
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