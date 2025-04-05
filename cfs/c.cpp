#include <bits/stdc++.h>

using namespace std;

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

const int MAXV = 1e8 + 1;
vector<int> ps;

void sieve() {
	vector<bool> isp(MAXV, 1);

	for (ll i = 2; i * i < MAXV; i++) {
		if (isp[i]) {
			for (ll j = i * i; j < MAXV; j += i) isp[j] = 0;
		}
	}
	for (int i = 2; i < MAXV; i++) {
		if (isp[i]) ps.pb(i);
	}
}

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;

	sieve();
	cerr << ps.size() << nl;
	while (N--) {
		ll X;
		cin >> X;
		ll t = X;

		ll ans = 1;
		for (int i = 0; i < ps.size() && ps[i] * ps[i] <= t; i++) {
			ll p = ps[i];
			if (t % p == 0) {
				ll cnt = 0;
				while (t % p == 0) {
					t /= p;
					cnt++;
				}
				ans *= (pow(p, cnt + 1) - 1) / (p - 1);
			}
		}

		if (t != 1) ans *= t + 1;
		cout << ans - X << nl;
	}
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