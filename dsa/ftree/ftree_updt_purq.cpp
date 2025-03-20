#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> ft;

void update(int i, int val) {
	for (; i <= n; i += i & -i) ft[i] += val;
}

long long query(int i) {
	long long ans = 0;
	for (; i > 0; i -= i & -i) ans += ft[i];
	return ans;
}

long long query(int l, int r) { return query(r) - query(l - 1); }

int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	cin >> n;
	ft.resize(n + 1);

	int q;
	cin >> q;
	while (q--) {
		int op, l, r, val;
		cin >> op;
		if (op == 1) {
			cin >> l >> val;
			update(l + 1, val);
		} else if (op == 2) {
			cin >> l >> r;
			cout << query(l + 1, r + 1) << '\n';
		}
	}
	cout << flush;
	return 0;
}