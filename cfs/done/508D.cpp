#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int base = 1000;
	int n;
	cin >> n;
	set<int> node;
	unordered_map<int, vector<pii>> adj;
	unordered_map<int, bool> edges;
	unordered_map<int, int> deg_in, deg_out;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int key = int(s[0]) * base + int(s[1]);
		int value = int(s[1]) * base + int(s[2]);
		node.insert(key), node.insert(value);
		adj[key].push_back({value, i});
		deg_in[value]++, deg_out[key]++;
	}

	int odd = 0, start = -1;
	for (int d : node) {
		if (deg_in[d] != deg_out[d]) {
			odd++;
			if (deg_out[d] == deg_in[d] + 1) {
				start = d;
			}
		}
	}

	if (odd == 0) start = *node.begin();
	if (odd != 0 && odd != 2 || start == -1) {
		cout << "NO" << nl;
		return;
	}

	vector<int> path;
	function<void(int)> dfs = [&](int u) {
		while (!adj[u].empty()) {
			auto [v, id] = adj[u].back();
			adj[u].pop_back();
			if (edges[id]) continue;
			edges[id] = 1;
			dfs(v);
		}

		path.push_back(u);
	};

	dfs(start);
	if (path.size() < n + 1) {
		cout << "NO" << nl;
		return;
	}
	cout << "YES" << nl;
	cout << char(path.back() / base % base);
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << char(path[i] % base);
	}
	cout << nl;
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