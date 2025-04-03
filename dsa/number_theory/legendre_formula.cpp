#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> ps;
unordered_map<ll, int> phi_cache;

void sieve(int n) {
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) isp[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
		if (isp[i]) ps.push_back(i);
}

int phi(ll n, int k) {
	if (k == 0) return n;
	ll key = n * 1e4 + k;
	if (phi_cache.contains(key)) return phi_cache[key];
	return phi_cache[key] = phi(n, k - 1) - phi(n / ps[k - 1], k - 1);
}

ll pi(ll n) {
	if (n < 2) return 0;
	sieve(sqrt(n));
	int s = ps.size();
	return phi(n, s) + s - 1;
}

int main() {
	cout << pi(1e9) << endl;
	return 0;
}