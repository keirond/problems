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

struct LCTree {
	vector<pair<int, int>> tree;

	LCTree *left = nullptr, *right = nullptr;

	ll eval(pair<int, int> line, int x) { return line.first * x + line.second; }

	void add(int node, int l, int r, int ql, int qr, pair<int, int> nw) {
		if (l > qr || r < ql) return;
		if (l <= ql && qr <= r) {
			// bool lef = eval(nw, l) < ;
			// bool mid = eval(nw, m) < ;

			if (mid) swap line
		}
		if (l == r) {
			tree[node] = nw;
			return;
		}

		int m = l + (r - l >> 1);
	}

	ll query(int node, int l, int r, int ql, int qr, int x) {
		if (l > qr || r < ql) return LLONG_MAX;
		if (r - l == 1) return eval(tree[node], x);
		int m = l + (r - l >> 1);
		ll ans = eval(tree[m], x);
		if (x <= m) return min(ans, query(node >> 1, l, m, ql, qr, x));
		return min(ans, query(node >> 1 | 1, m + 1, r, ql, qr, x));
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

	LiChaoTree cht(v_min, v_max);

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			dp[i] = toll[i];
		} else {
			dp[i] = toll[i] + cht.query(coor[i]);
		}

		pair<int, int> u;
		u.first = cost[i];
		u.second = dp[i] - cost[i] * coor[i];
		cht.insert(u);
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