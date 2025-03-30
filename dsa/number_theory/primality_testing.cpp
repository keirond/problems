#include <bits/stdc++.h>

using namespace std;

bool trial_division(int p) {
	if (p < 2) return false;
	for (int i = 2; i * i <= p; ++i) {
		if (p % i == 0) return false;
	}
	return true;
}

bool trial_division_odd_even_op(int p) {
	if (p < 2) return false;
	if (p % 2 == 0) return p == 2;
	for (int i = 3; i * i <= p; i += 2) {
		if (p % i == 0) return false;
	}
	return true;
}

bool trial_division_6k1_op(int p) {
	if (p < 2) return false;
	if (p == 2 || p == 3) return true;
	if (p % 2 == 0 || p % 3 == 0) return false;
	for (int i = 5; i * i <= p; i += 6) {
		if (p % i == 0 || p % (i + 2) == 0) return false;
	}
	return true;
}

long long sieve(long long n) {
	vector<int> ans(n, 1);
	ans[0] = ans[1] = 0;
	for (long long i = 2; i * i <= n; ++i) {
		if (ans[i])
			for (long long j = i * i; j <= n; j += i) ans[j] = 0;
	}
	return accumulate(ans.begin(), ans.end(), 0);
}

long long power(long long x, long long y, long long m) {
	long long ans = 1;
	x = x % m;
	while (y) {
		if (y & 1) ans = ((__int128)ans * x) % m;
		x = ((__int128)x * x) % m;
		y >>= 1;
	}
	return ans;
}

bool miller_test(long long n, int a, long long d, int s) {
	long long x = power(a, d, n);
	if (x == 1 || x == n - 1) return true;
	for (int i = 0; i < s - 1; ++i) {
		x = ((__int128)x * x) % n;
		if (x == n - 1) return true;
	}
	return false;
}

bool is_prime(long long n) {
	if (n < 2) return false;
	if (n % 2 == 0) return n == 2;
	long long d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		d >>= 1;
		++s;
	}

	vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (int a : bases) {
		if (a >= n) break;
		if (!miller_test(n, a, d, s)) return false;
	}
	return true;
}

int main() { return 0; }