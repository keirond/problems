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

vector<int> compute(string &pat) {
	int m = pat.size();
	vector<int> pi(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pat[i] != pat[j]) {
			j = pi[j - 1];
		}
		if (pat[i] == pat[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> kmp(string &txt, string &pat) {
	int n = txt.size(), m = pat.size();
	vector<int> pi = compute(pat), ans;
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && txt[i] != pat[j]) {
			j = pi[j - 1];
		}
		if (txt[i] == pat[j]) j++;
		if (j == m) {
			ans.push_back(i - m + 1);
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