#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;
	vector<ld> as(n);
	for (ld &d : as) cin >> d;

	ld exp = 1e-15;
	ld l = *min_element(as.begin(), as.end()),
	   r = *max_element(as.begin(), as.end());
	while (r - l > exp) {
		ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		ld t1 = 0, t2 = 0;
		ld mx_prefix = 0, mn_prefix = 0, prefix = 0;
		for (int i = 0; i < n; i++) {
			prefix += as[i] - m1;
			t1 = max({t1, abs(prefix - mx_prefix), abs(prefix - mn_prefix)});
			mx_prefix = max(mx_prefix, prefix);
			mn_prefix = min(mn_prefix, prefix);
		}
		mx_prefix = 0, mn_prefix = 0, prefix = 0;
		for (int i = 0; i < n; i++) {
			prefix += as[i] - m2;
			t2 = max({t2, abs(prefix - mx_prefix), abs(prefix - mn_prefix)});
			mx_prefix = max(mx_prefix, prefix);
			mn_prefix = min(mn_prefix, prefix);
		}
		if (t1 > t2) {
			l = m1;
		} else {
			r = m2;
		}
	}

	ld m1 = l, m2 = r;
	ld t1 = 0, t2 = 0;
	ld mx_prefix = 0, mn_prefix = 0, prefix = 0;
	for (int i = 0; i < n; i++) {
		prefix += as[i] - m1;
		t1 = max({t1, abs(prefix - mx_prefix), abs(prefix - mn_prefix)});
		mx_prefix = max(mx_prefix, prefix);
		mn_prefix = min(mn_prefix, prefix);
	}
	mx_prefix = 0, mn_prefix = 0, prefix = 0;
	for (int i = 0; i < n; i++) {
		prefix += as[i] - m2;
		t2 = max({t2, abs(prefix - mx_prefix), abs(prefix - mn_prefix)});
		mx_prefix = max(mx_prefix, prefix);
		mn_prefix = min(mn_prefix, prefix);
	}
	cout << fixed << setprecision(15) << min(t1, t2) << nl;
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