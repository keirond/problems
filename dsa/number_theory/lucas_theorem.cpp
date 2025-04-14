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

int p = 1327;
vector<int> fact, ifact;

int npow(int a) {
	int b = p - 2;
	a %= p;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return ans;
}

void preprocess() {
	fact.resize(p), ifact.resize(p);

	fact[0] = 1;
	for (int i = 1; i < p; i++) {
		fact[i] = 1LL * fact[i - 1] * i % p;
	}

	ifact[p - 1] = npow(fact[p - 1]);
	for (int i = p - 2; i >= 0; i--) {
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % p;
	}
}

void solve(int test_case [[maybe_unused]]) {
	int N, K;
	cin >> N >> K;

	preprocess();

	int ans = 1;
	while (K) {
		int n = N % p, k = K % p;
		if (k > n) {
			ans = 0;
			break;
		}
		int t = 1LL * fact[n] * ifact[k] % p * ifact[n - k] % p;
		ans = 1LL * ans * t % p;
		N /= p, K /= p;
	}
	cout << ans << nl;
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