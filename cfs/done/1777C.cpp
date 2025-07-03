#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;
	vector<int> as(n);
	for (int &d : as) cin >> d;
	sort(as.begin(), as.end());

	vector<int> sm(m);
	int cm = 0;
	int ans = INT_MAX;
	for (int r = 0, l = 0; r < n; r++) {
		int t = as[r];
		for (ll i = 2; i * i <= t; i++) {
			if (t % i == 0) {
				if (i <= m && sm[i - 1]++ == 0) {
					cm++;
				}
				if (t / i != i && t / i <= m && sm[t / i - 1]++ == 0) {
					cm++;
				}
			}
		}
		if (1 <= m && sm[0]++ == 0) {
			cm++;
		}
		if (t != 1 && t <= m && sm[t - 1]++ == 0) {
			cm++;
		}

		while (cm >= m && l <= r) {
			t = as[l];
			int cnt = 0;

			for (ll i = 2; i * i <= t; i++) {
				if (t % i == 0) {
					if (i <= m && sm[i - 1] == 1) {
						cnt++;
					}
					if (t / i != i && t / i <= m && sm[t / i - 1] == 1) {
						cnt++;
					}
				}
			}
			if (1 <= m && sm[0] == 1) {
				cnt++;
			}
			if (t != 1 && t <= m && sm[t - 1] == 1) {
				cnt++;
			}
			if (cnt) break;
			t = as[l++];
			for (ll i = 2; i * i <= t; i++) {
				if (t % i == 0) {
					if (i <= m && --sm[i - 1] == 0) {
						cm--;
					}
					if (t / i != i && t / i <= m && --sm[t / i - 1] == 0) {
						cm--;
					}
				}
			}
			if (1 <= m && --sm[0] == 0) {
				cm--;
			}
			if (t != 1 && t <= m && --sm[t - 1] == 0) {
				cm--;
			}
		}
		if (cm >= m && l <= r) {
			ans = min(ans, as[r] - as[l]);
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << nl;
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
