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

const int MAXV = 1e7 + 1;
const int MAXP = 7;
const int MAXK = 50;
const int MAXN = 2 * 3 * 7 * 5 * 11 * 13 * 17;	// product of first MAXP primes;

vector<int> ps;
vector<int> pi(MAXV), prod(MAXP);
vector<vector<int>> dp(MAXK, vector<int>(MAXN));

void sieve() {
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
}

void gen() {
	sieve();

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
	if (k == 0) return n;
	if (k < MAXK && n < MAXN) return dp[k][n];
	if (k < MAXP)
		return dp[k][n % prod[k - 1]] + n / prod[k - 1] * dp[k][prod[k - 1]];

	ll p = ps[k - 1];

	// pi(n) = phi(n, [sqrt(n)]) + [sqrt(n)] - 1
	// = phi(n, k) + k - 1 with k >= sqrt(n)
	if (n < MAXV && p * p >= n) return pi[n] - k + 1;

	// pi(n) = phi(n, [cbrt(n)]) + [cbrt(n)] - 1 - SUM(n/p_i)
	if (n < MAXV && p * p * p >= n) {
		int s = sqrt(n);
		ll ans = pi[n] - k + 1;
		for (int i = k; i < pi[s]; i++) ans += pi[n / ps[i]] - i;
		return ans;
	}

	return phi(n, k - 1) - phi(n / ps[k - 1], k - 1);
}

ll count(ll n) {
	if (n < MAXV) return pi[n];

	ll s = sqrt(n);
	ll c = cbrt(n);

	ll ans = phi(n, pi[c]) + pi[c] - 1;
	for (int i = pi[c]; i < pi[s]; i++) {
		ans -= count(n / ps[i]) - i;
	}
	return ans;
}

void solve(int test_case [[maybe_unused]] = 1) {
	gen();

	for (ll n = 1; n <= 1e13; n *= 10) {
		cout << n << ' ' << count(n) << nl;
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************