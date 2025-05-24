#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	string S;
	cin >> S;
	unordered_set<int> st;
	for (int i = 1; i <= 26; i++) {
		char c;
		cin >> c;
		if (c == '1') st.insert(i);
	}
	int K;
	cin >> K;

	int base = 101;
	int mod1 = 1e9 + 7;
	int mod2 = 1e9 + 9;

	vector<pair<ll, ll>> p(S.size() + 1);
	p[0].first = 1, p[0].second = 1;
	for (int i = 1; i <= S.size(); i++) {
		p[i].first = p[i - 1].first * base % mod1;
		p[i].second = p[i - 1].second * base % mod2;
	}

	struct lhash {
		size_t operator()(const pair<ll, ll> &p) const {
			return hash<ll>()(p.first) % (hash<ll>()(p.second) << 1);
		}
	};

	unordered_set<pair<ll, ll>, lhash> ans;
	for (int i = 1; i <= S.size(); i++) {
		int k = 0;
		ll h1 = 0, h2 = 0;
		for (int j = 0; j < i; j++) {
			int nw = S[j] - 'a' + 1;
			if (!st.contains(nw)) k++;
			h1 = (h1 * base + nw) % mod1;
			h2 = (h2 * base + nw) % mod2;
		}
		if (k <= K) ans.emplace(h1, h2);
		for (int j = i; j < S.size(); j++) {
			int nw = S[j] - 'a' + 1, od = S[j - i] - 'a' + 1;
			if (!st.contains(od)) k--;
			if (!st.contains(nw)) k++;
			h1 = (h1 * base % mod1 - p[i].first * od % mod1 + nw + mod1) % mod1;
			h2 =
				(h2 * base % mod2 - p[i].second * od % mod2 + nw + mod2) % mod2;
			if (k <= K) ans.emplace(h1, h2);
		}
	}
	cout << ans.size() << nl;
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