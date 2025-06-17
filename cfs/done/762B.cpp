#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int a, b, c;
	cin >> a >> b >> c;
	int m;
	cin >> m;
	vector<int> us, ps;
	for (int i = 0; i < m; i++) {
		int d;
		string type;
		cin >> d >> type;
		if (type == "USB") {
			us.push_back(d);
		} else {
			ps.push_back(d);
		}
	}
	sort(us.begin(), us.end());
	sort(ps.begin(), ps.end());
	int i = 0, j = 0;
	ll cost = 0;
	int cnt = 0;
	while (i < us.size() && a > 0) {
		a--;
		cnt++;
		cost += us[i];
		i++;
	}
	while (j < ps.size() && b > 0) {
		b--;
		cnt++;
		cost += ps[j];
		j++;
	}
	while ((i < us.size() || j < ps.size()) && c > 0) {
		c--;
		cnt++;
		if (i < us.size() && j < ps.size()) {
			if (us[i] < ps[j]) {
				cost += us[i++];
			} else {
				cost += ps[j++];
			}
		} else if (i < us.size()) {
			cost += us[i++];
		} else
			cost += ps[j++];
	}
	cout << cnt << ' ' << cost << nl;
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