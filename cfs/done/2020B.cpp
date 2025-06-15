#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	ll k;
	cin >> k;

	ll l = 1, r = LLONG_MAX, m;
	while (l <= r) {
		m = l + (r - l >> 1);
		ll cnt = m - (ll)(sqrtl(m));
		if (cnt < k)
			l = m + 1;
		else
			r = m - 1;
	}
	cout << l << nl;
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