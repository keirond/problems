#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr char nl = '\n';

void sieve(int n) {	 // up to 1e7
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i * i <= n; ++i) {
		if (isp[i])
			for (ll j = i * i; j <= n; j += i) isp[j] = 0;
	}
	for (int i = 2; i <= n; ++i)
		if (isp[i]) cout << i << ' ';
	cout << nl;
}

void bsieve(int n) {  // up to 1e7
	vector<int> ans((n >> 5) + 1);
	for (ll i = 2; i * i <= n; ++i) {
		if (!(ans[i >> 5] & (1 << (i & 31))))
			for (ll j = i * i; j <= n; j += i) ans[j >> 5] |= 1 << (j & 31);
	}
	for (ll i = 2; i <= n; ++i)
		if (!(ans[i >> 5] & (1 << (i & 31)))) cout << i << ' ';
	cout << nl;
}

void esieve(int n) {  // up to 1e8
	vector<int> ps;
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i <= n; ++i) {
		if (isp[i]) ps.push_back(i);
		for (int p : ps) {
			int t = i * p;
			if (t > n) break;
			isp[t] = 0;
			if (i % p == 0) break;
		}
	}
	for (int p : ps) cout << p << ' ';
	cout << nl;
}

void ssieve(ll l, ll r) {
	vector<ll> ps;
	// standard sieve for sqrt(n)
	vector<bool> isp(r - l + 1, 1);
	for (ll p : ps) {
		ll start = max(p * p, (l + p - 1) / p * p);
		for (ll j = start; j <= r; j += p) isp[j - l] = 0;
	}
	if (l == 1) isp[0] = 0;
	for (ll i = l; i <= r; ++i)
		if (isp[i - l]) cout << i << ' ';
	cout << nl;
}

int main() {
	sieve(1e7);
	bsieve(1e7);
	esieve(1e8);
	return 0;
}