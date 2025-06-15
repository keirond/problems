#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int &d : nums) cin >> d;
	sort(nums.begin(), nums.end());

	int l = nums[n / 2], r = l + k;
	while (l <= r) {
		ll t = 0;
		ll m = l + (r - l >> 1);
		for (int i = n / 2; i < n; i++) {
			t += max(0LL, m - nums[i]);
		}
		if (t <= k)
			l = m + 1;
		else
			r = m - 1;
	}
	cout << r << nl;
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