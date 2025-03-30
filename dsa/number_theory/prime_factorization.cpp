#include <bits/stdc++.h>

using namespace std;

vector<long long> trial_division(long long n) {
	vector<long long> ans;
	for (long long p = 2; p * p <= n; ++p) {
		while (n % p == 0) {
			ans.push_back(p);
			n /= p;
		}
	}

	if (n > 1) ans.push_back(n);
	return ans;
}

vector<long long> trial_division_odd_even_op(long long n) {
	vector<long long> ans;

	while (n % 2 == 0) {
		ans.push_back(2);
		n >>= 1;
	}

	long long p = 3;
	while (p * p <= n) {
		while (n % p == 0) {
			ans.push_back(p);
			n /= p;
		}
		p += 2;
	}

	if (n > 1) ans.push_back(n);
	return ans;
}

struct SPF {
	int N;
	vector<long long> spf;

	SPF() : N(1e5), spf(N) {}

	void sieve() {
		for (int i = 1; i < N; ++i) {
			spf[i] = i;
		}
		for (int i = 2; i * i < N; ++i) {
			if (spf[i] = i) {
				for (int j = i * i; j < N; j += i) {
					if (spf[j] = j) spf[j] = i;
				}
			}
		}
	}

	vector<long long> spf_method(long long n) {
		vector<long long> ans;
		while (n != 1) {
			ans.push_back(spf[n]);
			n /= spf[n];
		}
		return ans;
	}
};

using ll = long long;

ll mult(ll a, ll d, ll m) { return (__int128)a * d % m; }

ll f(ll a, ll c, ll m) { return (mult(a, a, m) + c) % m; }

ll rho(ll n) {
	if (n % 2 == 0) return 2;
	ll u = rand() % (n - 2) + 2, v = u;
	ll c = rand() % (n - 1) + 1, g = 1;
	while (g == 1) {
		u = f(u, c, n);
		v = f(v, c, n);
		v = f(v, c, n);
		g = gcd(abs(u - v), n);
	}
	if (g == n) return rho(n);
	return g;
}

ll pown(ll a, ll d, ll n) {
	ll ans = 1;
	a %= n;

	while (d) {
		if (d & 1) ans = (__int128)ans * a % n;
		a = (__int128)a * a % n;
		d >>= 1;
	}
	return ans;
}

bool miller_test(ll a, ll d, ll n, int s) {
	ll x = pown(a, d, n);
	if (x == 1 || x == n - 1) return true;

	for (int i = 0; i < s - 1; ++i) {
		x = (__int128)x * x % n;
		if (x == n - 1) return true;
	}
	return false;
}

bool is_prime(ll n) {
	if (n < 2) return false;
	if (n % 2 == 0) return n == 2;

	ll d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		s++;
		d >>= 1;
	}

	vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (ll a : bases) {
		if (a >= n) break;
		if (!miller_test(a, d, n, s)) return false;
	}
	return true;
}

void factorize(ll n, vector<ll> &ans) {
	if (n == 1) return;
	if (is_prime(n)) {
		ans.push_back(n);
		return;
	}

	ll d = rho(n);
	factorize(d, ans);
	factorize(n / d, ans);
}

int main() {
	srand(time(nullptr));

	return 0;
}