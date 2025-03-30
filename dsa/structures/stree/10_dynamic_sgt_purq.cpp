#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long val = 0;
	Node *left = nullptr, *right = nullptr;
};

struct STree {
	long long L, R;
	Node *root;

	STree(long long L, long long R) : L(L), R(R) { root = new Node(); }

	void update(Node *node, long long l, long long r, long long i,
				long long val) {
		if (l == r) {
			node->val += val;
			return;
		}
		long long m = l + ((r - l) >> 1);
		if (i <= m) {
			if (!node->left) node->left = new Node();
			update(node->left, l, m, i, val);
		} else {
			if (!node->right) node->right = new Node();
			update(node->right, m + 1, r, i, val);
		}
		node->val = (node->left ? node->left->val : 0) +
					(node->right ? node->right->val : 0);
	}

	void update(long long i, long long val) { update(root, L, R, i, val); }

	long long query(Node *node, long long l, long long r, long long ql,
					long long qr) {
		if (!node || ql > r || qr < l) return 0;
		if (ql <= l && r <= qr) return node->val;
		long long m = l + ((r - l) >> 1);
		return query(node->left, l, m, ql, qr) +
			   query(node->right, m + 1, r, ql, qr);
	}

	long long query(long long l, long long r) {
		return query(root, L, R, l, r);
	}
};

int main() { return 0; }