#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> l >> r;
		if (2 * l <= r)
			cout << l << ' ' << 2 * l << nl;
		else
			cout << -1 << ' ' << -1 << nl;
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