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

vector<int> compute(string &s) {
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> kmp(string &s, string &pat) {
	int n = s.size(), m = pat.size();
	vector<int> pi = compute(pat);

	vector<int> ans;
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != pat[j]) j = pi[j - 1];
		if (s[i] == pat[j]) j++;
		if (j == m) {
			ans.pb(i - m + 1);
			j = pi[j - 1];
		}
	}
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	string txt, pat;
	getline(cin, txt);
	getline(cin, pat);

	vector<int> ans = kmp(txt, pat);
	for (int d : ans) cout << d << ' ';
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