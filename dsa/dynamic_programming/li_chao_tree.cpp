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

struct LiChaoTree {
	vector<int> stop;
	vector<pair<int, int>> tree;

	LiChaoTree(int l, int r) {
		int n = r - l + 1 << 2;
		tree.assign(n, {-1, -1});
		stop.assign(n, -1);
	}

	ll eval(pair<int, int> line, int x) {
		if (line.first == -1) return LLONG_MAX;
		return line.first * x + line.second;
	}

	void insert(int node, int l, int r, pair<int, int> nw, int s) {
		int m = l + (r - l >> 1);
		bool lef = eval(nw, l) < eval(tree[node], l);
		bool mid = eval(nw, m) < eval(tree[node], m);
		if (mid) {
			swap(tree[node], nw);
			swap(stop[node], s);
		}
		if (l == r)
			return;
		else if (lef != mid)
			insert(node << 1, l, m - 1, nw, s);
		else
			insert(node << 1 | 1, m + 1, r, nw, s);
	}

	pair<ll, int> query(int node, int l, int r, int x) {
		int m = l + (r - l >> 1);
		ll ans = eval(tree[node], x);
		if (l == r) return {ans, stop[node]};
		if (x <= m) {
			auto [t1, t2] = query(node << 1, l, m, x);
			if (t1 < ans) return {t1, t2};
			return {ans, stop[node]};
		}
		auto [t1, t2] = query(node << 1 | 1, m + 1, r, x);
		if (t1 < ans) return {t1, t2};
		return {ans, stop[node]};
	}
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> coor(N), toll(N), cost(N);
	for (int &d : coor) cin >> d;
	for (int &d : cost) cin >> d;
	for (int &d : toll) cin >> d;

	vector<ll> dp(N);

	int v_mn = *min_element(all(coor)), v_mx = *max_element(all(coor));

	LiChaoTree cht(v_mn, v_mx);

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			dp[i] = toll[i];
			cout << 0 << ' ' << dp[i] << ' ';
		} else {
			auto [t1, v] = cht.query(1, v_mn, v_mx, coor[i]);
			dp[i] = toll[i] + t1;
			cout << v << ' ' << cost[v] << "*(" << coor[i] << '-' << coor[v]
				 << ")+" << toll[i] << "=" << dp[i] << ' ';
		}

		pair<int, int> u;
		u.first = cost[i];
		u.second = dp[i] - cost[i] * coor[i];
		cout << u.first << ' ' << u.second << nl;
		cht.insert(1, v_mn, v_mx, u, i);
	}

	cout << dp[N - 1] << nl;
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