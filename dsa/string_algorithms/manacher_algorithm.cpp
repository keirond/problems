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
	string str;
	getline(cin, str);

	int n = str.size(), m = 2 * n + 1;
	string temp(m, '/');
	for (int i = 0; i < m; i++) {
		if (i % 2) temp[i] = str[i / 2];
	}

	vector<int> ans(m);
	for (int i = 1, c = 1, r = 0; i < m; i++) {
		if (i < c + r) {
			ans[i] = min(ans[2 * c - i], c + r - i);
		}
		while (i - ans[i] >= 0 && i + ans[i] < m &&
			   temp[i - ans[i]] == temp[i + ans[i]]) {
			ans[i]++;
		}
		if (i + ans[i] > c + r) {
			c = i, r = ans[i];
		}
	}
	ans[0] = 1;

	int u = 0, v = 0;
	for (int i = 0; i < m; i++) {
		if (ans[i] > v) {
			u = i;
			v = ans[i];
		}
	}

	string res;
	for (int i = u - ans[u] + 1; i < u + ans[u]; i++) {
		if (temp[i] != '/') res.pb(temp[i]);
	}
	cout << res << nl;
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