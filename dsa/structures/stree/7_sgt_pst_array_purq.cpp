#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long val;
	int left, right;
};

struct STree {
	int n;
	int node_count;
	vector<Node> tree;
	vector<int> undo_versions, redo_versions;

	STree(vector<int> &nums) {
		n = nums.size();
		node_count = 0;
		build(nums, 0, n - 1);
	}

	int new_node(long long val) {
		if (node_count >= tree.size())
			tree.push_back({val, -1, -1});
		else
			tree[node_count] = {val, -1, -1};
		return node_count++;
	}

	int new_node(int left, int right) {
		if (node_count >= tree.size())
			tree.push_back({tree[left].val + tree[right].val, left, right});
		else
			tree[node_count] = {tree[left].val + tree[right].val, left, right};
		return node_count++;
	}

	int build(vector<int> &nums, int l, int r) {
		if (l == r) return new_node(nums[l]);
		int m = l + ((r - l) >> 1);
		return new_node(build(nums, l, m), build(nums, m + 1, r));
	}

	int update(int node, int l, int r, int i, int val) {
		if (l == r) return new_node(val);
		int m = l + ((r - l) >> 1);
		if (i <= m) {
			return new_node(update(tree[node].left, l, m, i, val),
							tree[node].right);
		}
		return new_node(tree[node].left,
						update(tree[node].right, m + 1, r, i, val));
	}

	void update(int i, int val) {
		undo_versions.push_back(node_count);
		redo_versions.clear();
		update(node_count - 1, 0, n - 1, i, val);
	}

	long long query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node].val;
		int m = l + ((r - l) >> 1);
		return query(tree[node].left, l, m, ql, qr) +
			   query(tree[node].right, m + 1, r, ql, qr);
	}

	long long query(int l, int r) {
		return query(node_count - 1, 0, n - 1, l, r);
	}

	void undo(int times) {
		while (!undo_versions.empty() && times--) {
			redo_versions.push_back(node_count);
			node_count = undo_versions.back();
			undo_versions.pop_back();
		}
	}

	void redo(int times) {
		while (!redo_versions.empty() && times--) {
			undo_versions.push_back(node_count);
			node_count = redo_versions.back();
			redo_versions.pop_back();
		}
	}
};

int main() {
	int N;
	cin >> N;
	vector<int> nums(N);
	for (auto &d : nums) cin >> d;

	STree st(nums);

	int M;
	cin >> M;
	cin.ignore();
	while (M--) {
		int op, x, y;
		cin >> op;
		if (op == 1) {
			cin >> x >> y;
			st.update(x, y);
		} else if (op == 2) {
			cin >> x >> y;
			cout << st.query(x, y) << '\n';
		} else if (op == 3) {
			st.undo(1);
		} else if (op == 4) {
			st.redo(1);
		}
	}
	return 0;
}