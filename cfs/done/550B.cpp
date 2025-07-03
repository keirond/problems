#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, L, R, x;
	cin >> n >> L >> R >> x;
	vector<int> cs(n);
	for (int &d : cs) cin >> d;
	sort(cs.begin(), cs.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (cs[j] - cs[i] < x) continue;
			int t = j - i + 1;
			for (int u = 0; u < (1 << t); u++) {
				if (!(u & 1)) continue;
				if (!(u & (1 << (t - 1)))) continue;
				ll sm = 0;
				for (int v = 0; v < t; v++) {
					if (u & (1 << v)) sm += cs[i + v];
				}
				if (sm >= L && sm <= R) ans++;
			}
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