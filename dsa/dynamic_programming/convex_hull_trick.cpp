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
	vector<int> coor(N), toll(N), cost(N);
	for (int &d : coor) cin >> d;
	for (int &d : cost) cin >> d;
	for (int &d : toll) cin >> d;

	vector<vector<int>> pack(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		pack[i][0] = coor[i];
		pack[i][1] = cost[i];
		pack[i][2] = toll[i];
	}

	sort(all(pack));
	for (int i = 0; i < N; i++) {
		coor[i] = pack[i][0];
		cost[i] = pack[i][1];
		toll[i] = pack[i][2];
	}

	vector<ll> dp(N);
	deque<pair<ll, ll>> dq;

	auto bad = [&](pair<int, int> v1, pair<int, int> v2, pair<int, int> v3) {
		return (v2.second - v1.second) * (v1.first - v3.first) >=
			   (v3.second - v1.second) * (v1.first - v2.first);
	};

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			dp[i] = toll[i];
		} else {
			while (dq.size() > 1 && dq[0].first * coor[i] + dq[0].second >=
										dq[1].first * coor[i] + dq[1].second) {
				dq.pop_front();
			}
			dp[i] = toll[i] + dq.front().first * coor[i] + dq.front().second;
		}

		pair<int, int> u;
		u.first = cost[i];
		u.second = dp[i] - cost[i] * coor[i];
		while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), u)) {
			dq.pop_back();
		}
		dq.push_back(u);
	}

	cout << dp[N - 1] << nl;
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