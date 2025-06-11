#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Node {
	Node *left = nullptr, *right = nullptr, *parent = nullptr;
	int key = 0;
	int value = 0;
	int sum = 0;

	// this signals that the path from x to the root should be reversed
	bool revert = false;
	Node(int key, int val) : key(key), value(val) {}

	bool is_root() {
		return !parent || (parent->left != this && parent->right != this);
	}
	void push() {
		if (revert) {
			swap(left, right);
			if (left) left->revert ^= 1;
			if (right) right->revert ^= 1;
			revert = false;
		}
	}

	void update() {
		sum = value;
		if (left) sum += left->sum;
		if (right) sum += right->sum;
	}

	void rotate() {
		Node *p = parent;
		Node *g = p->parent;

		if (p->left == this) {
			p->left = right;
			if (right) right->parent = p;
			right = p;
		} else {
			p->right = left;
			if (left) left->parent = p;
			left = p;
		}

		parent = g;
		p->parent = this;

		if (g) {
			if (g->left == p) g->left = this;
			if (g->right == p) g->right = this;
		}

		p->update();
		update();
	}

	void splay() {
		while (!is_root()) {
			Node *p = parent;
			Node *g = p->parent;

			if (!p->is_root()) g->push();
			p->push();
			push();

			if (!p->is_root()) {
				if ((p->left == this) == (g->left == p)) {
					p->rotate();
				} else {
					rotate();
				}
			}
			rotate();
		}
		push();
	}
};

// make x the top node of its preferred path, effectively exposing the path fro
// x to the root
void access(Node *x) {
	Node *last = nullptr;
	for (Node *t = x; t; t = t->parent) {
		t->splay();
		t->right = last;
		t->update();
		last = t;
	}
	x->splay();
}

// make x the root of entire tree
void make_root(Node *x) {
	access(x);
	x->revert ^= 1;
}

// connect u -> v, assumming u is a root & u and v are in different trees.
void link(Node *u, Node *v) {
	make_root(u);
	u->parent = v;
}

// cut the edges between u and its parent;
void cut(Node *u, Node *v) {
	make_root(u);
	access(v);
	if (v->left == u && !u->right) {
		v->left = nullptr;
		u->parent = nullptr;
		v->update();
	}
}

// **************************************************************************

// return the root of tree containing x.
Node *find_root(Node *x) {
	access(x);
	while (x->left) {
		x->push();
		x = x->left;
	}
	x->splay();
	return x;
}

bool connected(Node *u, Node *v) { return find_root(u) == find_root(v); }

//
int depth(Node *u);

// return the lowest common accestor of u and v
Node *lca(Node *u, Node *v);

//
int path_sum(Node *u, Node *v) {
	make_root(u);
	access(v);
	return v->sum;
}

void update(Node *x, int val) {
	access(x);
	x->value = val;
	x->update();
}

void path_update(Node *u, Node *v, int val);  // require Lazy Propagation

void solve(int test_case [[maybe_unused]]) {
	int n, q;
	cin >> n >> q;
	vector<Node *> tr(n);
	for (int i = 0; i < n; i++) {
		int key, val;
		cin >> key >> val;
		tr[i] = new Node(key, val);
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		link(tr[v], tr[u]);
	}

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			cout << path_sum(tr[u], tr[v]) << nl;
		} else if (op == 2) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			cout << (connected(tr[u], tr[v]) ? "YES" : "NO") << nl;
		} else if (op == 3) {
			int u, val;
			cin >> u >> val;
			u--;
			update(tr[u], val);
		}
	}
}

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