#include <bits/stdc++.h>

using namespace std;

constexpr char nl [[maybe_unused]] = '\n';

// --------------------------------------------------------------------------
// Data structures (only Leetcode)

template <typename T> struct LinkedListNode;
template <typename T> struct BinaryTreeNode;

template <typename T> struct LinkedListNode {
	T val;
	LinkedListNode *next;

	LinkedListNode() : val(T()), next(nullptr) {}
	LinkedListNode(T x) : val(x), next(nullptr) {}
	LinkedListNode(T x, LinkedListNode *next) : val(x), next(next) {}
};

template <typename T> struct BinaryTreeNode {
	T val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode() : val(T()), left(nullptr), right(nullptr) {}
	BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
	BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right)
		: val(x), left(left), right(right) {}
};

#define ListNode LinkedListNode<int>
#define TreeNode BinaryTreeNode<int>

// --------------------------------------------------------------------------
// Read methods (only Leetcode)

template <typename T> void __read(stringstream &ss, T &value) { ss >> value; }

void __read(stringstream &ss, char &value) {
	char c;
	ss >> c >> value >> c;
}

void __read(stringstream &ss, string &value) {
	char c;
	ss >> c, getline(ss, value, '"');
}

template <typename T, typename V>
void __read(stringstream &ss, pair<T, V> &values) {
	char c;
	ss >> c;
	__read(ss, values.first);
	ss >> c;
	__read<V>(ss, values.second);
	ss >> c;
}

template <typename T> void __read(stringstream &ss, vector<T> &values) {
	char c;
	ss >> c;

	while (ss.peek() != ']') {
		T value;
		__read(ss, value);
		values.push_back(value);
		ss >> c;
		if (c == ']') break;
	}
}

template <typename T, typename... V> void _read(T &t, V &...v) {
	string str;
	getline(cin, str);
	stringstream ss(str);
	__read(ss, t);
	_read(v...);
}

// --------------------------------------------------------------------------

template <typename T> void __print(const T &x);
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T, typename V, typename K>
void __print(const tuple<T, V, K> &x);

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

// Print methods (only Leetcode)
template <typename T> void __print(LinkedListNode<T> *x) {
	int f = 0;
	auto *y = x;
	while (y) cerr << (f++ ? " -> " : ""), __print(y->val), y = y->next;
}

template <typename T> void __print(BinaryTreeNode<T> *x) {
	if (x)
		while (x)
			__print(x->val), cerr << " [ ", __print(x->left), __print(x->right),
				cerr << " ] ";
}

template <typename T> void __print(const T &x) {
	int f = 0;
	cerr << '{';
	for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
	cerr << "}";
}

template <typename T, typename V> void __print(const pair<T, V> &x) {
	cerr << '{', __print(x.first), cerr << ", ", __print(x.second), cerr << '}';
}

template <typename T, typename V, typename K>
void __print(const tuple<T, K, V> &x) {
	cerr << '{', __print(get<0>(x)), cerr << ", ", __print(get<1>(x)),
		cerr << ", ", __print(get<2>(x)), cerr << '}';
}

// --------------------------------------------------------------------------

void _print() { cerr << ']' << nl; }

template <typename T, typename... V> void _print(T t, V... v) {
	__print(t);
	if (sizeof...(v)) cerr << ", ";
	_print(v...);
}

#ifdef DEBUG
#define dbg(x...)                                                             \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
	_print(x);                                                                \
	cerr << "\e[39m";
#else
#define dbg(x...)
#endif

// --------------------------------------------------------------------------

struct STree {
	int n;
	vector<int> tree, lazy;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(n << 2, 0);
		lazy.assign(n << 2, 0);
		build(nums, 1, 0, n - 1);
	}

	void build(vector<int> &nums, int node, int l, int r) {
		if (l == r) {
			tree[node] = nums[l];
			return;
		}
		int m = l + (r - l >> 1);
		build(nums, node << 1, l, m);
		build(nums, node << 1 | 1, m + 1, r);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	void push(int node, int l, int r) {
		if (lazy[node]) {
			tree[node] += lazy[node] * (r - l + 1);
			if (l != r) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update(int node, int l, int r, int ql, int qr, int val) {
		push(node, l, r);
		if (qr < l || r < ql) return;
		if (ql <= l && r <= qr) {
			lazy[node] += val;
			push(node, l, r);
			return;
		}
		int m = l + (r - l >> 1);
		update(node << 1, l, m, ql, qr, val);
		update(node << 1 | 1, m + 1, r, ql, qr, val);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	int query(int node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) +
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

	int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test_cases = 1;
	// cin >> test_cases;
	while (test_cases--) {
		solve(test_cases);
		cout << flush;
	}
	return 0;
}