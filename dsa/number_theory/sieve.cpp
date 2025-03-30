#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void sieve(ll n) {
	vector<ll> ans(n + 1, 1);
	ans[0] = ans[1] = 0;
	for (ll i = 2; i * i <= n; ++i) {
		if (ans[i]) {
			for (ll j = i * i; j <= n; j += i) ans[j] = 0;
		}
	}
	for (ll i = 0; i <= n; ++i)
		if (ans[i]) cout << i << ' ';
	cout << '\n';
}

void bsieve(ll n) {
	vector<ll> ans((n >> 5) + 1);
	ans[0] |= 3;
	for (ll i = 2; i * i <= n; ++i) {
		if (!(ans[i >> 5] & (1 << (i & 31)))) {
			for (ll j = i * i; j <= n; j += i) ans[j >> 5] |= 1 << (j & 31);
		}
	}
	for (ll i = 0; i <= n; ++i)
		if (!(ans[i >> 5] & (1 << (i & 31)))) cout << i << ' ';
	cout << '\n';
}

void bsieve_bitset(ll n) {
	bitset<10000001> ans;
	ans.set();
	ans[0] = ans[1] = 0;
}

void ssieve(ll l, ll r) {
	vector<ll> primes = {};	 // sieve((ll)sqrt(r));
	vector<bool> is_primes(r - l + 1, 1);
	for (auto p : primes) {
		ll start = max(p * p, (l + p - 1) / p * p);
		for (ll j = start; j <= r; j += p) is_primes[j - l] = 0;
	}

	if (l == 1) is_primes[0] = 0;
	for (ll i = l; i <= r; ++i)
		if (is_primes[i - l]) cout << i << ' ';
	cout << '\n';
}

void esieve(ll n) {
	vector<ll> primes;
	vector<bool> is_primes(n + 1, 1);
	is_primes[0] = is_primes[1] = 0;
	for (ll i = 2; i * i <= n; ++i) {
		if (is_primes[i]) primes.push_back(i);
		for (auto p : primes) {
			ll x = i * p;
			if (x > n) break;
			is_primes[x] = 0;
			if (i % p == 0) break;
		}
	}
}

int main() {
	ll n = 234;
	sieve(n);
	bsieve(n);
	return 0;
}