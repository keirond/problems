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

vector<int> suffix_array(string &s) {
	s += "$";
	int n = s.size();

	vector<int> sa(n), rank(n), tmp(n), lcp;

	for (int i = 0; i < n; i++) {
		sa[i] = i;
		rank[i] = s[i];
	}

	for (int k = 1; k < n; k <<= 1) {
		auto cmp = [&](int i, int j) {
			if (rank[i] != rank[j]) return rank[i] < rank[j];
			int ri = (i + k < n) ? rank[i + k] : -1;
			int rj = (j + k < n) ? rank[j + k] : -1;
			return ri < rj;
		};
		sort(all(sa), cmp);

		tmp[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		}
		rank = tmp;
	}
	return sa;
}

vector<int> lcp_array(string &s, vector<int> &sa) {
	int n = s.size();
	vector<int> rank(n), lcp(n - 1);

	for (int i = 0; i < n; i++) {
		rank[sa[i]] = i;
	}

	int h = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i] == 0) continue;
		int j = sa[rank[i] - 1];
		while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
		lcp[rank[i] - 1] = h;
		if (h > 0) h--;
	}
	return lcp
}

void solve(int test_case [[maybe_unused]]) {
	string s;
	cin >> s;

	vector<int> sa = suffix_array(s);
	for (int d : sa) cout << d << ' ';
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