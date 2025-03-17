#include <bits/stdc++.h>

using namespace std;

struct STree {
	int n;
	vector<int> tree;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(4 * n, 0);
		build(nums, 1, 0, n - 1);
	}

	void build(vector<int> &nums, int node, int l, int r) {
		if (l == r) {
			tree[node] = nums[l];
			return;
		}
		int m = l + (r - l >> 1);
		build(nums, node << 1, l, m);
		build(nums, node << 1 | 1, m + 1, r);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	void update(int node, int l, int r, int i, int val) {
		if (l == r) {
			tree[node] = val;
			return;
		}
		int m = l + (r - l >> 1);
		if (i <= m)
			update(node << 1, l, m, i, val);
		else
			update(node << 1 | 1, m + 1, r, i, val);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	int query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) +
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	void update(int i, int val) { update(1, 0, n - 1, i, val); }

	int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() { return 1; }