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

	priority_queue<int> pq;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if (d == 0 && !pq.empty()) {
			ans += pq.top();
			pq.pop();
		} else {
			pq.push(d);
		}
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
