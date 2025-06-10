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
	bool reversed = false;
	int sum = 0;

	Node(int key, int value) : key(key), value(value) {}

	void pull();
	void push();
	void update();
};

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
}

void access(Node *u) {
	Node *last = nullptr;
	while (u) {
		splay(u);
		u->left = last;
		last = u;
		u = u->parent;
	}
}

// Tree Queries
Node *find_root(Node *u);
int lca(Node *u, Node *v);
int depth(Node *u);

// Tree Modifications
void link(Node *u, Node *v);
void cut(Node *u, Node *v);
void make_root(Node *u) {
	access(u);
	splay(u);
	u->rev ^= 1;
	u->push();
}

// Path Operations
int path_sum(Node *u, Node *v) {
	make_root(u);
	access(v);
	splay(v);
	return v->sum;
}

int path_max(Node *u, Node *v);
void path_update(Node *u, Node *v, int val);

void update(Node *u, int val);

int path_query(Node *u, Node *v) {
	make_root(u);
	access(v);
	return v->subtree_value;
}

bool connected(Node *u, Node *v);

void solve(int test_case [[maybe_unused]]) {
	int n, q;
	cin >> n >> q;
	vector<Node *> tr(n);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		tr[i] = new Node(val);
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
			cout << path_query(tr[u], tr[v]) << nl;
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