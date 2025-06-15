#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;
	vector<pii> pairs;
	for (int i = 0; i < n; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		pairs.push_back({a1, a2});
	}

	sort(pairs.begin(), pairs.end(), [](auto x, auto y) {
		int u = min(x.first, x.second);
		int v = min(y.first, y.second);
		if (u == v) return max(x.first, x.second) < max(y.first, y.second);
		return u < v;
	});

	for(auto &d: pairs) {
		cout << d.first << ' ' << d.second << ' ';
	}
	cout << nl;
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