#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long val;
	Node *left, *right;

	Node() : val(0), left(nullptr), right(nullptr) {}
	Node(long long val) : val(val), left(nullptr), right(nullptr) {}
};

struct STree {
	int n;
	Node *root;
	vector<Node *> undo_versions;

	STree(vector<int> &nums) {
		n = nums.size();
		root = build(nums, 0, n - 1);
	}

	Node *build(vector<int> &nums, int l, int r) {
		if (l == r) return new Node(nums[l]);
		int m = l + (r - l >> 1);
		auto node = new Node();
		node->left = build(nums, l, m);
		node->right = build(nums, m + 1, r);
		node->val = node->left->val + node->right->val;
		return node;
	}

	Node *update(Node *node, int l, int r, int i, int val) {
		if (l == r) return new Node(val);
		int m = l + (r - l >> 1);
		auto new_node = new Node();
		if (i <= m) {
			new_node->left = update(node->left, l, m, i, val);
			new_node->right = node->right;
		} else {
			new_node->left = node->left;
			new_node->right = update(node->right, m + 1, r, i, val);
		}
		new_node->val = new_node->left->val + new_node->right->val;
		return new_node;
	}

	void update(int i, int val) {
		undo_versions.push_back(root);
		root = update(root, 0, n - 1, i, val);
	}

	long long query(Node *node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return node->val;
		int m = l + (r - l >> 1);
		return query(node->left, l, m, ql, qr) +
			   query(node->right, m + 1, r, ql, qr);
	}

	long long query(int l, int r) { return query(root, 0, n - 1, l, r); }

	void undo(int times) {
		while (!undo_versions.empty() && times--) {
			root = undo_versions.back();
			undo_versions.pop_back();
		}
	}
};

int main() {
	vector<int> nums = {1, 2, 3, 4, 5};
	STree st(nums);

	cout << "Sum of range [1, 3]: " << st.query(1, 3) << endl;

	st.update(2, 10);
	cout << "After update: Sum of range [1, 3]: " << st.query(1, 3) << endl;

	st.undo(1);
	cout << "After undo: Sum of range [1, 3]: " << st.query(1, 3) << endl;

	return 0;
}