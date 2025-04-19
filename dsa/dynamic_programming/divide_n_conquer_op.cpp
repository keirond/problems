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

vector<ll> dp, ndp;
vector<vector<ll>> cost;

void compute(int l, int r, int optl, int optr) {
	if (l > r) return;
	int m = l + (r - l >> 1);

	int opt = -1;
	ll mn = LLONG_MAX;
	for (int k = optl; k <= min(m, optr); k++) {
		ll t = (k ? dp[k - 1] : 0) + cost[k][m];
		if (t < mn) {
			mn = t;
			opt = k;
		}
	}
	ndp[m] = mn;
	compute(l, m - 1, optl, opt);
	compute(m + 1, r, opt, optr);
}

void solve(int test_case [[maybe_unused]]) {
	int n, k;
	cin >> n >> k;

	vector<ll> nums(n);
	for (ll &d : nums) cin >> d;

	cost.assign(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		for (int j = i; j < n; j++) {
			sum += nums[j];
			cost[i][j] = sum * sum;
		}
	}

	dp.assign(n, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = cost[i][i];
	}

	for (int i = 1; i < k; i++) {
		ndp.assign(n, 0);
		compute(0, n - 1, 0, n - 1);
		swap(dp, ndp);
	}

	cout << dp[n - 1] << nl;
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