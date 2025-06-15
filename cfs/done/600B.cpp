#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, m;
	cin >> n >> m;
	vector<int> as(n);
	for (int &d : as) cin >> d;

	sort(as.begin(), as.end());
	for (int i = 0; i < m; i++) {
		int d;
		cin >> d;
		cout << upper_bound(as.begin(), as.end(), d) - as.begin() << ' ';
	}
	cout << nl;
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