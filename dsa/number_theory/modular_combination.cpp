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

const int m = 1e9 + 9;

int egcd(int a, int b) {
	int x = 1, y = 0;
	int x1 = 0, y1 = 1;
	while (b) {
		int q = a / b;
		a %= b;
		swap(a, b);
		x -= q * x1;
		swap(x, x1);
		y -= q * y1;
		swap(y, y1);
	}
	return (x % m + m) % ::m;
}

ll _exp(ll a) {
	ll b = m - 2;
	ll ans = 1;
	a %= m;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;

	vector<int> fact(N + 1);
	vector<int> inv_fact(N + 1), inv_fact_1(N + 1);
	fact[0] = inv_fact[0] = inv_fact_1[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = 1LL * fact[i - 1] * i % m;
		inv_fact[i] = egcd(fact[i], m);
		inv_fact_1[i] = _exp(fact[i]);
	}

	// cout << 1LL * fact[N] * inv_fact[M] % m * inv_fact[N - M] % m << nl;

	int cnt = 0;
	for (int M = 0; M <= N; M++) {
		int ans = 1LL * fact[N] * inv_fact[M] % m * inv_fact[N - M] % m;
		int ans_1 = 1LL * fact[N] * inv_fact_1[M] % m * inv_fact_1[N - M] % m;
		if (ans == ans_1) cnt++;
	}

	cout << cnt << '/' << N + 1 << " passed!" << nl;
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