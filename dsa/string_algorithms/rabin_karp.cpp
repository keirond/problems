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

const int p = 31;
const int mod = 1e9 + 9;

vector<int> rabin_karp(string &txt, string &pat) {
	int n = txt.size(), m = pat.size();
	vector<ll> p_pow(max(n, m));
	p_pow[0] = 1;

	for (int i = 1; i < p_pow.size(); i++) {
		p_pow[i] = p_pow[i - 1] * p % mod;
	}

	ll h_pat = 0;
	for (int i = 0; i < m; i++) {
		h_pat = (h_pat + (pat[i] - 'a' + 1) * p_pow[i]) % mod;
	}

	vector<ll> h(n + 1, 0);
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + (txt[i] - 'a' + 1) * p_pow[i]) % mod;
	}

	vector<int> ans;
	for (int i = 0; i + m <= n; i++) {
		ll cur_h = (h[i + m] - h[i] + mod) % mod;
		if (cur_h == h_pat * p_pow[i] % mod) ans.pb(i);
	}
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	string txt, pat;
	getline(cin, txt);
	getline(cin, pat);

	vector<int> ans = rabin_karp(txt, pat);
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