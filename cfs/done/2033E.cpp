#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int &d : nums) cin >> d;

	int ans = 0;

	vector<bool> vt(n);
	for (int i = 0; i < n; i++) {
		if (vt[i] || nums[i] == i + 1) continue;
		vt[i] = 1;
		int j = i + 1;
		int cnt = 1;
		while (nums[j - 1] != i + 1) {
			cnt++;
			j = nums[j - 1];
			vt[j - 1] = 1;
		}
		if (cnt % 2) cnt++;
		ans += cnt / 2 - 1;
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