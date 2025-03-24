#include <bits/stdc++.h>

using namespace std;

struct FTree {
	int n, m;
	vector<vector<long long>> ft1, ft2, ft3, ft4;

	FTree(int n, int m)
		: n(n),
		  m(m),
		  ft1(n + 1, vector<long long>(m + 1, 0)),
		  ft2(n + 1, vector<long long>(m + 1, 0)),
		  ft3(n + 1, vector<long long>(m + 1, 0)),
		  ft4(n + 1, vector<long long>(m + 1, 0)) {}

	void update(vector<vector<long long>> &ft, int x, int y, int val) {
		for (int i = x; i <= n; i += i & -i) {
			for (int j = y; j <= m; j += j & -j) {
				ft[i][j] += val;
			}
		}
	}

	void update(int x1, int y1, int x2, int y2, int val) {
		update(ft1, x1, y1, val);
		update(ft1, x1, y2 + 1, -val);
		update(ft1, x2 + 1, y1, -val);
		update(ft1, x2 + 1, y2 + 1, val);

		update(ft2, x1, y1, val * (x1 - 1));
		update(ft2, x1, y2 + 1, -val * (x1 - 1));
		update(ft2, x2 + 1, y1, -val * x2);
		update(ft2, x2 + 1, y2 + 1, val * x2);

		update(ft3, x1, y1, val * (y1 - 1));
		update(ft3, x1, y2 + 1, -val * y2);
		update(ft3, x2 + 1, y1, -val * (y1 - 1));
		update(ft3, x2 + 1, y2 + 1, val * y2);

		update(ft4, x1, y1, val * (x1 - 1) * (y1 - 1));
		update(ft4, x1, y2 + 1, -val * (x1 - 1) * y2);
		update(ft4, x2 + 1, y1, -val * x2 * (y1 - 1));
		update(ft4, x2 + 1, y2 + 1, val * x2 * y2);
	}

	long long query(vector<vector<long long>> &ft, int x, int y) {
		long long ans = 0;
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) {
				ans += ft[i][j];
			}
		}
		return ans;
	}

	long long query(int x, int y) {
		return query(ft1, x, y) * x * y - query(ft2, x, y) * y -
			   query(ft3, x, y) * x + query(ft4, x, y);
	}

	long long query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) +
			   query(x1 - 1, y1 - 1);
	}
};

int main() { return 0; }