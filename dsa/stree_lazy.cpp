#include <bits/stdc++.h>

using namespace std;

struct STree {
	int n;
	vector<long long> tree, lazy;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
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

	void push(int node, int l, int r) {
		if (lazy[node]) {
			tree[node] += lazy[node] * (r - l + 1);
			if (l != r) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update(int node, int l, int r, int ql, int qr, int val) {
		push(node, l, r);
		if (qr < l || ql > r) return;
		if (ql <= l && r <= qr) {
			lazy[node] += val;
			push(node, l, r);
			return;
		}
		int m = l + (r - l >> 1);
		update(node << 1, l, m, ql, qr, val);
		update(node << 1 | 1, m + 1, r, ql, qr, val);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	long long query(int node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) +
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

	long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() { return 1; }