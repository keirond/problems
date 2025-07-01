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
	vector<int> xs(n), ts(n);
	for (int &d : xs) cin >> d;
	for (int &d : ts) cin >> d;

	ld exp = 1e-9;
	ld l = 0, r = 1e9;
	while (r - l > exp) {
		ld m = (l + r) / 2;
		ld left = 0, right = 0;
		for (int i = 0; i < n; i++) {
			if (xs[i] < m) {
				left = max(left, (ld)ts[i] + m - xs[i]);
			} else {
				right = max(right, (ld)ts[i] + xs[i] - m);
			}
		}
		if (left > right) {
			r = m;
		} else {
			l = m;
		}
	}

	ld left = LLONG_MAX, right = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		left = min(left, (ld)ts[i] + abs(l - xs[i]));
		right = min(right, (ld)ts[i] + abs(r - xs[i]));
	}
	if (left < right)
		cout << fixed << setprecision(6) << l << nl;
	else
		cout << fixed << setprecision(6) << r << nl;
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
