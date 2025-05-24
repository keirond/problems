#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	string X, Y;
	cin >> X >> Y;
	int x = 0, y = 0, z = 0;
	for (char c : X) {
		if (c == '+')
			x++;
		else
			y++;
	}
	for (char c : Y) {
		if (c == '+')
			x--;
		else if (c == '-')
			y--;
		else
			z++;
	}
	if (x < 0 || y < 0)
		cout << 0 << nl;
	else {
		long double ans = 1;
		for (int i = 1; i <= z; i++) {
			ans = ans * i / 2;
		}
		for (int i = 1; i <= x; i++) {
			ans = ans / i;
		}
		for (int i = 1; i <= y; i++) {
			ans = ans / i;
		}
		cout << fixed << setprecision(12) << ans << nl;
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