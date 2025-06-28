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
	vector<int> nums(n);
	for (int &d : nums) cin >> d;
	for (int i = 1; i < n; i++) {
		nums[i] += nums[i - 1];
	}

	int m;
	cin >> m;
	while (m--) {
		int d;
		cin >> d;
		int it = lower_bound(nums.begin(), nums.end(), d) - nums.begin();
		cout << it + 1 << nl;
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