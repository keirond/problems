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
	int tn = n, t = 0;
	while (tn) {
		t++;
		tn /= 10;
	}

	ll ans = LLONG_MAX;
	if (t % 2) t++;
	for (int i = 0; i < (1 << t); i++) {
		int tc = 0, ti = i;
		while (ti) {
			ti &= ti - 1;
			tc++;
		}
		if (tc != t / 2) continue;
		ll curr = 0;
		for (int j = 0; j < t; j++) {
			if (i & (1 << j))
				curr = curr * 10 + 4;
			else
				curr = curr * 10 + 7;
		}
		if (curr >= n) ans = min(ans, curr);
	}
	if (ans == LLONG_MAX) {
		t += 2;
		for (int i = 0; i < (1 << t); i++) {
			int tc = 0, ti = i;
			while (ti) {
				ti &= ti - 1;
				tc++;
			}
			if (tc != t / 2) continue;
			ll curr = 0;
			for (int j = 0; j < t; j++) {
				if (i & (1 << j))
					curr = curr * 10 + 4;
				else
					curr = curr * 10 + 7;
			}
			if (curr > n) ans = min(ans, curr);
		}
	}
	cout << ans << nl;
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
