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

const int MAXV = 1e6 + 1;
const int MAXP = 7;
const int MAXK = 50;
const int MAXN = 2 * 3 * 5 * 7 * 11 * 13 * 17;

vector<int> pi(MAXV), prod(MAXP), ps;
vector<vector<int>> dp(MAXK, vector<int>(MAXN));

void gen() {
	bitset<MAXV> isp;
	isp.set();

	for (int i = 2; i * i < MAXV; i++) {
		if (isp[i]) {
			for (int j = i * i; j < MAXV; j += i) isp[j] = 0;
		}
	}

	for (int i = 2; i < MAXV; i++) {
		if (isp[i]) ps.pb(i);
		pi[i] = pi[i - 1] + isp[i];
	}

	prod[0] = ps[0];
	for (int i = 1; i < MAXP; i++) prod[i] = prod[i - 1] * ps[i];

	for (int i = 0; i < MAXN; i++) dp[0][i] = i;
	for (int i = 1; i < MAXK; i++) {
		for (int j = 1; j < MAXN; j++) {
			dp[i][j] = dp[i - 1][j] - dp[i - 1][j / ps[i - 1]];
		}
	}
}
ll phi(ll n, int k) {
	if (!k) return n;
	if (k < MAXK && n < MAXN) return dp[k][n];
	if (k < MAXP)
		return dp[k][n % prod[k - 1]] + n / prod[k - 1] * dp[k][prod[k - 1]];

	ll p = ps[k - 1];
	if (n < MAXV && p * p >= n) return pi[n] - k + 1;
	if (n < MAXV && p * p * p >= n) {
		int s = sqrt(n);
		ll ans = pi[n] - k + 1;
		for (int i = k; i < pi[s]; i++) ans += pi[n / ps[i]] - i;
		return ans;
	}
	return phi(n, k - 1) - phi(n / p, k - 1);
}

ll count(ll n) {
	if (n < MAXV) return pi[n];

	ll s = sqrt(n), c = cbrt(n);

	ll ans = phi(n, pi[c]) + pi[c] - 1;
	for (int i = pi[c]; i < pi[s]; i++) ans -= count(n / ps[i]) - i;
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	ll N;
	cin >> N;

	gen();
	if (N <= ps.size()) {
		cout << ps[N - 1] << nl;
		return;
	}
	ll l = N * (log(N) - log(log(N)) - .6);
	ll r = N * (log(N) + log(log(N)) + .9);
	while (l < r) {
		ll m = l + (r - l >> 1);
		if (count(m) >= N)
			r = m;
		else
			l = m + 1;
	}
	cout << l << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************