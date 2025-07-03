#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, k;
	cin >> n >> k;
	vector<int> as(n);
	for (int &d : as) cin >> d;

	int l = 0, ans = 0;
	while (l < n) {
		int r = l;
		for (; r < n - 1; r++) {
			if (as[r] >= 2 * as[r + 1]) break;
		}
		ans += max(0, r - l - k + 1);
		l = r + 1;
	}
	cout << ans << nl;
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
