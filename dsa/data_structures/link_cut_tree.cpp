#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Node {
	Node *left, *right, *parent;
	bool reversed;
	int value, subtree_value;

	void push();
	void update();
};

void splay(Node *x);
void access(Node *x);
void make_root(Node *x);
void link(Node *child, Node *parent);
void cut(Node *x);
Node *find_root(Node *x);

void solve(int test_case [[maybe_unused]]) {
	
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