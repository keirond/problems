#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Node {
	Node *left = nullptr, *right = nullptr, *parent = nullptr;
	int key = 0;
	int val = 0;

	Node(int key, int val) : key(key), val(val) {}
};

Node *root = nullptr;

void rotate(Node *x) {
	Node *p = x->parent;
	if (!p) return;
	Node *g = p->parent;

	p->parent = x;
	x->parent = g;
	if (p->left == x) {
		p->left = x->right;
		if (x->right) x->right->parent = p;
		x->right = p;
	} else {
		p->right = x->left;
		if (x->left) x->left->parent = p;
		x->left = p;
	}

	if (g) {
		if (g->left == p)
			g->left = x;
		else
			g->right = x;
	} else {
		root = x;
	}
}

void splay(Node *x) {
	while (x->parent) {
		Node *p = x->parent;
		Node *g = p->parent;

		if (!g) {
			rotate(x);
		} else if ((g->left == p) == (p->left == x)) {
			rotate(p);
			rotate(x);
		} else {
			rotate(x);
			rotate(x);
		}
	}
	root = x;
}

Node *find_node(int key) {
	Node *x = root;
	while (x) {
		if (key == x->key) break;
		if (key < x->key) {
			if (!x->left) break;
			x = x->left;
		} else {
			if (!x->right) break;
			x = x->right;
		}
	}
	return x;
}

void insert(int key, int val) {
	if (!root) {
		root = new Node(key, val);
		return;
	}

	Node *x = find_node(key);
	if (x->key == key) {
		x->val = val;
		splay(x);
		return;
	}

	Node *nN = new Node(key, val);
	nN->parent = x;
	if (key < x->key) {
		x->left = nN;
	} else {
		x->right = nN;
	}
	splay(nN);
}

bool find(int key) {
	if (!root) return false;
	Node *x = find_node(key);
	splay(x);
	return x->key == key;
}

void erase(int key) {
	if (!root) return;
	if (!find(key)) return;
	Node *x = root;

	if (!x->left) {
		root = root->right;
		if (root) root->parent = nullptr;
	} else if (!x->right) {
		root = root->left;
		if (root) root->parent = nullptr;
	} else {
		Node *left = x->left;
		left->parent = nullptr;

		Node *max_left = left->right;
		while (max_left->right) {
			max_left = max_left->right;
		}
		
		splay(max_left);
		max_left->right = x->right;
		if (x->right) x->right->parent = max_left;
		root = max_left;
	}
	delete x;
}

void inorder(Node *x) {
	if (!x) return;
	inorder(x->left);
	cout << x->key << ' ';
	inorder(x->right);
}

void solve(int test_case [[maybe_unused]]) {}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	cout << flush;
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************