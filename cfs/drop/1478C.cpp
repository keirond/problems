#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;
	vector<ll> ds(2 * n);
	for (ll &d : ds) cin >> d;
	vector<ll> as(n);
	sort(ds.begin(), ds.end());
	for (int i = 0; i < 2 * n; i += 2) {
		if (ds[i] != ds[i + 1] || ds[i] % 2) {
			cout << "NO" << nl;
			return;
		}
		as[i / 2] = ds[i];
	}
	ll sm = as[0] / 2;
	vector<ll> ts(n);
	for (int i = 1; i < n; i++) {
		ts[i] = (as[i] - as[i - 1]) / 2 / i;
	}
	ll tm = 0;
	for (int i = 0; i < n; i++) {
		tm += ts[i];
		sm -= tm;
	}
	if (sm % n || sm <= 0) {
		cout << "NO" << nl;
		return;
	}
	cout << "YES" << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int test_cases = 1;
	cin >> test_cases;
	while (test_cases--) {
		solve(test_cases);
		cout << flush;
	}
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************
