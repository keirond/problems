#include <bits/stdc++.h>

using namespace std;

struct FTree {
	int n;
	vector<long long> ft;
	vector<int> nums;

	FTree(int n, vector<int> &nums) : n(n), ft(n + 1), nums(nums) {}

	void assign(int i, int val) {
		update(i, val - nums[i - 1]);
		nums[i - 1] = val;
	}

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
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	FTree ft(N, nums);

	int Q;
	cin >> Q;
	while (Q--) {
		int op, l, r, val;
		cin >> op;
		if (op == 1) {
			cin >> l >> val;
			ft.assign(l + 1, val);
		} else if (op == 2) {
			cin >> l >> r;
			cout << ft.query(l + 1, r + 1) << '\n';
		}
	}
	cout << flush;
	return 0;
}