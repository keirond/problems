#include <bits/stdc++.h>

using namespace std;

struct MergeSortTree {
	int n;
	vector<vector<int>> tree;

	MergeSortTree(vector<int> nums) {
		n = nums.size();
		tree.resize(n << 2);
		build(nums, 1, 0, n - 1);
	}

	void build(vector<int>& nums, int node, int l, int r) {
		if (l == r) {
			tree[node] = {nums[l]};
			return;
		}
		int m = l + ((r - l) >> 1);
		build(nums, node << 1, l, m);
		build(nums, node << 1 | 1, m + 1, r);
		merge(tree[node << 1].begin(), tree[node << 1].end(),
			  tree[node << 1 | 1].begin(), tree[node << 1 | 1].end(),
			  back_inserter(tree[node]));
	}

	int countLowerEqual(int node, int l, int r, int ql, int qr, int x) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && r <= qr) {
			return upper_bound(tree[node].begin(), tree[node].end(), x) -
				   tree[node].begin();
		}
		int m = l + ((r - l) >> 1);
		return countLowerEqual(node << 1, l, m, ql, qr, x) +
			   countLowerEqual(node << 1 | 1, m + 1, r, ql, qr, x);
	}

	int countGreater(int node, int l, int r, int ql, int qr, int x) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && r <= qr) {
			return tree[node].end() -
				   upper_bound(tree[node].begin(), tree[node].end(), x);
		}
		int m = l + ((r - l) >> 1);
		return countGreater(node << 1, l, m, ql, qr, x) +
			   countGreater(node << 1 | 1, m + 1, r, ql, qr, x);
	}

	int countInRange(int node, int l, int r, int ql, int qr, int a, int b) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && r <= qr) {
			return upper_bound(tree[node].begin(), tree[node].end(), b) -
				   lower_bound(tree[node].begin(), tree[node].end(), a);
		}
		int m = l + ((r - l) >> 1);
		return countInRange(node << 1, l, m, ql, qr, a, b) +
			   countInRange(node << 1 | 1, m + 1, r, ql, qr, a, b);
	}

	int countInRange(int l, int r, int a, int b) {
		return countInRange(1, 0, n - 1, l, r, a, b);
	}

	int kthSmallest(int ql, int qr, int k) {
		int l = -1e9, r = 1e9;
		while (l < r) {
			int m = l + ((r - l) >> 1);
			int cnt = countLowerEqual(1, 0, n - 1, ql, qr, m);
			if (cnt < k)
				l = m + 1;
			else
				r = m;
		}
		return l;
	}

	int countInversions(vector<int>& nums) {
		int ans = 0;
		for (int i = 1; i < nums.size(); ++i) {
			ans += countGreater(1, 0, n - 1, 0, i - 1, nums[i]);
		}
		return ans;
	}
};

int main() { return 0; }