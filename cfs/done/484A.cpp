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
	while (n--) {
		ll l, r;
		cin >> l >> r;

		ll ans = r, cz = 0;
		for (int i = 0; i < 64; i++) {
			if (!(r & (1LL << i))) cz++;
			if (cz && (r & (1LL << i))) {
				ll t = (r & ~((1LL << i) - 1)) - 1;
				if (t < l || t > r) break;
				ans = min(ans, t);
			}
		}

		cout << ans << nl;
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
