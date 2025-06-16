#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;
	vector<int> as(n), bs(m);
	for (int &d : as) cin >> d;
	sort(as.begin(), as.end());
	for (int &d : bs) cin >> d;
	sort(bs.begin(), bs.end());

	int l = as.front(), r = bs.back();
	while (r - l > 1) {
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		ll t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++) {
			t1 += max(0, m1 - as[i]);
			t2 += max(0, m2 - as[i]);
		}
		for (int i = 0; i < m; i++) {
			t1 += max(0, bs[i] - m1);
			t2 += max(0, bs[i] - m2);
		}

		if (t1 > t2)
			l = m1 + 1;
		else
			r = m2 - 1;
	}
	ll t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		t1 += max(0, l - as[i]);
		t2 += max(0, r - as[i]);
	}
	for (int i = 0; i < m; i++) {
		t1 += max(0, bs[i] - l);
		t2 += max(0, bs[i] - r);
	}
	cout << min(t1, t2) << nl;
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