#include <bits/stdc++.h>

using namespace std;

struct FTree {
	int n;
	vector<long long> ft1, ft2;

	void update(vector<long long> &ft, int i, int val) {
		for (; i <= n; i += i & -i) ft[i] += val;
	}

	void update(int l, int r, int val) {
		update(ft1, l, val);
		update(ft1, r + 1, -val);
		update(ft2, l, val * (l - 1));
		update(ft2, r + 1, -val * r);
	}

	long long query(int i) {
		long long sum1 = 0, sum2 = 0;
		for (int j = i; j > 0; j -= j & -j) {
			sum1 += ft1[j];
			sum2 += ft2[j];
		}
		return sum1 * i - sum2;
	}

	long long query(int l, int r) { return query(r) - query(l - 1); }
};

int main() { return 1; }