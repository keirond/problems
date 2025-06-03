#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> edges;

	for (int i = 0; i < M; i++) {
		int U, V, W;
		cin >> U >> V >> W;
		U--, V--;
		edges.push_back({U, V, W});
	}

	sort(edges.begin(), edges.end(),
		 [](auto &u, auto &v) { return u[2] < v[2]; });

	vector<int> parent(N), size(N, 1);
	iota(parent.begin(), parent.end(), 0);

	function<int(int)> find = [&](int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	};

	function<bool(int, int)> unite = [&](int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) return false;
		if (size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a] += size[b];
		return true;
	};

	ll total = 0;
	for (auto &d : edges) {
		if (unite(d[0], d[1])) total += d[2];
	}
	cout << total << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	cout << flush;
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************