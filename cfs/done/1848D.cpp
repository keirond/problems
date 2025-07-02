#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	ll s, k;
	cin >> s >> k;

	auto get = [&](int m) -> ll {
		ll ts = s;
		if (m == 0) return ts * k;
		ll tm = m;
		int t = ts % 10;
		if (t == 0 || t == 5) {
			ts += ts % 10;
		} else if (t % 2 == 0) {
			ts += tm / 4 * 20;
			for (int i = 0; i < (tm % 4); i++) {
				ts += ts % 10;
			}
		} else {
			tm--;
			ts += ts % 10;
			ts += tm / 4 * 20;
			for (int i = 0; i < (tm % 4); i++) {
				ts += ts % 10;
			}
		}
		return ts * (k - m);
	};

	int t = s % 10;
	if (t == 0) {
		cout << s * k << nl;
		return;
	}
	if (t == 5) {
		cout << max(s * k, (s + 5) * (k - 1)) << nl;
		return;
	}
	ll ans = s * k;
	if (t % 2) {
		s += s % 10;
		k--;
	}

	for (int i = 0; i < 4; i++) {
		int l = 0, r = k / 4;
		while (r - l > 1) {
			int m1 = l + (r - l) / 3;
			int m2 = r - (r - l) / 3;
			ll sm1 = get(4 * m1), sm2 = get(4 * m2);
			if (sm1 < sm2)
				l = m1 + 1;
			else
				r = m2 - 1;
		}
		ans = max(ans, get(4 * l));
		ans = max(ans, get(4 * r));
		s += s % 10;
		k--;
	}
	cout << ans << nl;
	// b * k -> (b + 20) * (k-4)
	// 4b -> 20*(k-4)
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
