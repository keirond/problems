#include <bits/stdc++.h>

using namespace std;

struct FTree {
	int n, m;
	vector<vector<long long>> ft;

	FTree(int n, int m) : n(n), m(m), ft(n + 1, vector<long long>(m + 1, 0)) {}

	void update(int x, int y, int val) {
		for (int i = x; i <= n; i += i & -i) {
			for (int j = y; j <= m; j += j & -j) {
				ft[i][j] += val;
			}
		}
	}

	long long query(int x, int y) {
		long long ans = 0;
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) {
				ans += ft[i][j];
			}
		}
		return ans;
	}

	long long query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) +
			   query(x1 - 1, y1 - 1);
	}
};

int main() { return 0; }