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

vector<int> ps;
vector<int> pi_small;
unordered_map<ll, ll> phi_cache, pi_cache;

void sieve(int n) {
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) isp[j] = 0;
		}
	}

	pi_small.resize(n);
	for (int i = 2; i <= n; i++) {
		if (isp[i]) ps.pb(i);
		pi_small[i] = pi_small[i - 1] + isp[i];
	}
}

ll phi(ll x, int a) {
	if (a == 0) return x;
	ll key = (x << 20) | a;
	if (phi_cache.contains(key)) return phi_cache[key];

	ll result = phi(x, a - 1) - phi(x / ps[a - 1], a - 1);
	return phi_cache[key] = result;
}

ll pi(ll n) {
	if (n <= 1e6) return pi_small[n];

	if (pi_cache.contains(n)) return pi_cache[n];

	ll sqrt_n = sqrt(n);
	ll cbrt_n = cbrt(n);

	int a = pi(cbrt_n);
	ll result = phi(n, a) + a - 1;
	for (int i = a; i <= ps.size() && ps[i] <= sqrt_n; i++) {
		result -= pi(n / ps[i]) - i;
	}
	return pi_cache[n] = result;
}

void solve(int test_case [[maybe_unused]] = 1) {
	sieve(1e6);
	for (ll n = 1; n <= 1e11; n *= 10) {
		cout << n << ' ' << pi(n) << nl;
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