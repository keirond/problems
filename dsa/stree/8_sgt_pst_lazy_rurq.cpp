#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long val, lazy;
	Node *left, *right;

	Node() : val(0), lazy(0), left(nullptr), right(nullptr) {}
	Node(long long val) : val(val), lazy(0), left(nullptr), right(nullptr) {}
};

struct STree {
	int n;
	Node *root;
	vector<Node *> undo_versions, redo_versions;

	STree(vector<int> &nums) {
		n = nums.size();
		root = build(nums, 0, n - 1);
	}

	Node *build(vector<int> &nums, int l, int r) {
		if (l == r) return new Node(nums[l]);
		int m = l + ((r - l) >> 1);
		auto node = new Node();
		node->left = build(nums, l, m);
		node->right = build(nums, m + 1, r);
		node->val = node->left->val + node->right->val;
		return node;
	}

	void push(Node *node, int l, int r) {
		if (node->lazy) {
			node->val += node->lazy * (r - l + 1);
			if (l != r) {
				node->left = new Node(*node->left);
				node->right = new Node(*node->right);
				node->left->lazy += node->lazy;
				node->right->lazy += node->lazy;
			}
			node->lazy = 0;
		}
	}

	Node *update(Node *node, int l, int r, int ql, int qr, int val) {
		push(node, l, r);
		if (qr < l || ql > r) return node;
		if (ql <= l && r <= qr) {
			auto new_node = new Node(*node);
			new_node->lazy += val;
			push(new_node, l, r);
			return new_node;
		}
		int m = l + ((r - l) >> 1);
		auto new_node = new Node();
		new_node->left = update(node->left, l, m, ql, qr, val);
		new_node->right = update(node->right, m + 1, r, ql, qr, val);
		new_node->val = new_node->left->val + new_node->right->val;
		return new_node;
	}

	void update(int l, int r, int val) {
		undo_versions.push_back(root);
		redo_versions.clear();
		root = update(root, 0, n - 1, l, r, val);
	}

	long long query(Node *node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return node->val;
		int m = l + ((r - l) >> 1);
		return query(node->left, l, m, ql, qr) +
			   query(node->right, m + 1, r, ql, qr);
	}

	long long query(int l, int r) { return query(root, 0, n - 1, l, r); }

	void undo(int times) {
		while (!undo_versions.empty() && times--) {
			redo_versions.push_back(root);
			root = undo_versions.back();
			undo_versions.pop_back();
		}
	}

	void redo(int times) {
		while (!redo_versions.empty() && times--) {
			undo_versions.push_back(root);
			root = redo_versions.back();
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
		int op, l, r, val;
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> val;
			st.update(l, r, val);
		} else if (op == 2) {
			cin >> l >> r;
			cout << st.query(l, r) << '\n';
		} else if (op == 3) {
			st.undo(1);
		} else if (op == 4) {
			st.redo(1);
		}
	}
	return 0;
}