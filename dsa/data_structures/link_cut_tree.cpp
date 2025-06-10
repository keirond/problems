#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Node {
	Node *left = nullptr, *right = nullptr, *parent = nullptr;
	bool reversed = false;
	int value = 0;
	int subtree_value = 0;

	Node(int val) : value(val) {}
};

void push(Node *x) {
	if (!x || !x->reversed) return;
	swap(x->left, x->right);
	if (x->left) x->left->reversed ^= 1;
	if (x->right) x->right->reversed ^= 1;
	x->reversed = 0;
}

void pull();
void update();
void splay(Node *x) { x->push(); }

void access(Node *x) { splay(x); }

void make_root(Node *x) {
	access(x);
	x->reversed ^= 1;
	x->push();
}

void link(Node *child, Node *parent);
void cut(Node *x);
Node *find_root(Node *x);

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