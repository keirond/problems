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

int mul(ll a, ll b, int m) {
	a %= m;
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % m;
		a = a * 2 % m;
		b >>= 1;
	}
	return ans;
}

int exp(ll a, ll b, int m) {
	a %= m;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	int T;
	cin >> T;
	while (T--) {
		string A, B;
		cin >> A >> B;
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