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

vector<int> ps;

void sieve(int n) {
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		if (isp[i]) ps.pb(i);
		for (int p : ps) {
			ll t = i * p;
			if (t > n) break;
			isp[t] = 0;
			if (i % p == 0) break;
		}
	}
}

void solve(int test_case [[maybe_unused]]) {
	for (int n = 1; n <= 1e8; n *= 10) {
		ps.clear();
		sieve(n);
		cout << ps.size() << nl;
	}
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