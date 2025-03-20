#include <bits/stdc++.h>

using namespace std;

struct FTree {
	int n;
	vector<long long> ft;

	FTree(int n) : n(n), ft(n + 1) {}

	void update(int i, int val) {
		for (; i <= n; i += i & -i) ft[i] += val;
	}

	long long query(int i) {
		int ans = 0;
		for (; i > 0; i -= i & -i) ans += ft[i];
		return ans;
	}

	long long query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
	int N;
	cin >> N;
	FTree ft(N);

	int Q;
	cin >> Q;
	while (Q--) {
		int op, l, r, val;
		cin >> op;
		if (op == 1) {
			cin >> l >> val;
			ft.update(l + 1, val);
		} else if (op == 2) {
			cin >> l >> r;
			cout << ft.query(l + 1, r + 1) << '\n';
		}
	}
	cout << flush;
	return 0;
}