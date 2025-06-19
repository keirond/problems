#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;
	vector<int> bs(n);
	for (int &d : bs) cin >> d;
	vector<int> gs(m);
	for (int &d : gs) cin >> d;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)bs[i] * m;
	}

	sort(bs.begin(), bs.end());
	sort(gs.begin(), gs.end());
	int mx = bs[n - 1], nmx = bs[n - 2];
	if (bs.back() > gs.front()) {
		cout << "-1" << nl;
		return;
	}
	for (int i = 1; i < m; i++) {
		ans += gs[i] - mx;
	}
	if (bs.back() == gs.front())
		ans += gs.front() - mx;
	else
		ans += gs.front() - nmx;
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