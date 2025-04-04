#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> sieve(int n) {
	vector<int> ps;
	vector<bool> isp(n + 1, 1);

	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) isp[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
		if (isp[i]) ps.push_back(i);
	return ps;
}

int pi_sieve(int n) {
	vector<bool> isp(n + 1, 1);

	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) isp[j] = 0;
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; i++)
		if (isp[i]) ans++;
	return ans;
}

ll pi(ll n) {
	if (n < 2) return 0;
	if (n <= 1e6) return pi_sieve(n);

	int m = sqrt(n);
	vector<int> ps = sieve(m);

	
}

int main() {
	// counting prime up to 1e12
	ll n = 1e9;
	cout << pi(n) << endl;
	return 0;
}