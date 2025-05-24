#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> scores;
	for (int i = 0; i < N; i++) {
		int p, t;
		cin >> p >> t;
		scores.push_back({p, t});
	}

	sort(scores.begin(), scores.end(), [](auto &x, auto &y) {
		return x.first > y.first || x.first == y.first && x.second < y.second;
	});

	vector<int> cnt;
	int count = 1;
	for (int i = 1; i < N; i++) {
		auto &x = scores[i - 1];
		auto &y = scores[i];
		if (x.first == y.first && x.second == y.second)
			count++;
		else {
			cnt.push_back(count);
			count = 1;
		}
	}
	cnt.push_back(count);

	int k = 0;
	for (int i = 0; i < cnt.size(); i++) {
		k += cnt[i];
		if (k >= K) {
			cout << cnt[i] << nl;
			return;
		}
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
// **************************************************************************t