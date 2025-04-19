#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> nums(N);
	for (auto &d : nums) cin >> d;

	vector<vector<int>> dp(N, vector<int>(N)), opt(N, vector<int>(N));
	auto C = [&](int i, int j) {
		ll ans = 0;
		for (int k = i; k <= j; k++) {
			ans += nums[k];
		}
		return ans;
	};

	for (int i = 0; i < N; i++) {
		opt[i][i] = i;
		dp[i][i] = nums[i];
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			ll mn = LLONG_MAX;
			ll cost = C(i, j);
			for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
				ll t = dp[i][k] + dp[k + 1][j] + cost;
				if (t < mn) {
					opt[i][j] = k;
					mn = t;
				}
			}
			dp[i][j] = mn;
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << nl;
	}

	cout << dp[0][N - 1] << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************