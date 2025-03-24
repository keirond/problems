#include <bits/stdc++.h>

using namespace std;

struct STree {
	int n;
	vector<long long> tree;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(n << 1, 0);

		for (int i = 0; i < n; ++i) {
			tree[i + n] = nums[i];
		}
		for (int i = n - 1; i > 0; --i) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}

	void update(int i, int val) {
		for (tree[i += n] = val; i > 1; i >>= 1) {
			tree[i >> 1] = tree[i] + tree[i ^ 1];
		}
	}

	long long query(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ans += tree[l++];
			if (!(r & 1)) ans += tree[r--];
		}
		return ans;
	}
};

int main() { return 1; }