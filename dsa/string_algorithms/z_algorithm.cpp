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

vector<int> zF(string &s) {
	int n = s.size();
	vector<int> z(n);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	z[0] = n;
	return z;
}

void solve(int test_case [[maybe_unused]]) {
	string txt, pat;
	getline(cin, txt);
	getline(cin, pat);

	int n = txt.size(), m = pat.size();
	string str = pat + "&" + txt;
	vector<int> z = zF(str);
	for (int i = m + 1; i < n + m + 1; i++) {
		if (z[i] == m) cout << i - m - 1 << ' ';
	}
	cout << nl;
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