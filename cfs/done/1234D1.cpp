#include <bits/stdc++.h>

using namespace std;

constexpr char nl [[maybe_unused]] = '\n';

// --------------------------------------------------------------------------

template <typename T> void __info(const T &x);
template <typename T, typename V> void __info(const pair<T, V> &x);
template <typename T, typename V, typename K>
void __info(const tuple<T, V, K> &x);

void __info(int x) { cerr << x; }
void __info(long x) { cerr << x; }
void __info(long long x) { cerr << x; }
void __info(unsigned x) { cerr << x; }
void __info(unsigned long x) { cerr << x; }
void __info(unsigned long long x) { cerr << x; }
void __info(float x) { cerr << x; }
void __info(double x) { cerr << x; }
void __info(long double x) { cerr << x; }
void __info(char x) { cerr << '\'' << x << '\''; }
void __info(const char *x) { cerr << '\"' << x << '\"'; }
void __info(const string &x) { cerr << '\"' << x << '\"'; }
void __info(bool x) { cerr << (x ? "true" : "false"); }

template <typename T> void __info(const T &x) {
	int f = 0;
	cerr << '{';
	for (auto &i : x) cerr << (f++ ? ", " : ""), __info(i);
	cerr << "}";
}

template <typename T, typename V> void __info(const pair<T, V> &x) {
	cerr << '{', __info(x.first), cerr << ", ", __info(x.second), cerr << '}';
}

template <typename T, typename V, typename K>
void __info(const tuple<T, K, V> &x) {
	cerr << '{', __info(get<0>(x)), cerr << ", ", __info(get<1>(x)),
		cerr << ", ", __info(get<2>(x)), cerr << '}';
}

void __print() { cerr << ']' << nl; }

template <typename T, typename... V> void __print(T t, V... v) {
	__info(t);
	if (sizeof...(v)) cerr << ", ";
	__print(v...);
}

#ifdef INFO
#define enable_info() cerr << "Enabling debug logging..." << nl;
#define info(x...)                                                            \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
	__print(x);                                                               \
	cerr << "\e[39m";
#else
#define enable_info()
#define info(x...)
#endif

// **************************************************************************

struct STree {
	int n;
	vector<int> tree;

	STree(string &s) {
		n = s.size();
		tree.assign(n << 2, 0);
		build(s, 1, 0, n - 1);
	}

	void build(string &s, int node, int l, int r) {
		if (l == r) {
			int idx = s[l] - 'a';
			tree[node] = 1 << idx;
			return;
		}
		int m = l + (r - l >> 1);
		build(s, node << 1, l, m);
		build(s, node << 1 | 1, m + 1, r);
		tree[node] = tree[node << 1] | tree[node << 1 | 1];
	}

	void update(int node, int l, int r, int i, int val) {
		if (l == r) {
			tree[node] = val;
			return;
		}
		int m = l + (r - l >> 1);
		if (i <= m)
			update(node << 1, l, m, i, val);
		else
			update(node << 1 | 1, m + 1, r, i, val);
		tree[node] = tree[node << 1] | tree[node << 1 | 1];
	}

	void update(int i, char c) {
		int idx = c - 'a';
		update(1, 0, n - 1, i, 1 << idx);
	}

	int query(int node, int l, int r, int ql, int qr) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) |
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	int query(int l, int r) {
		int t = query(1, 0, n - 1, l, r);
		int ans = 0;
		while (t) {
			ans++;
			t &= t - 1;
		}
		return ans;
	}
};

void solve(int test_case [[maybe_unused]]) {
	string S;
	cin >> S;

	STree st(S);

	int N;
	cin >> N;
	while (N--) {
		int op, l, r;
		char c;
		cin >> op;
		if (op == 1) {
			cin >> l >> c;
			st.update(l - 1, c);
		} else if (op == 2) {
			cin >> l >> r;
			cout << st.query(l - 1, r - 1) << '\n';
		}
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	enable_info();

	int test_cases = 1;
	// cin >> test_cases;
	while (test_cases--) {
		solve(test_cases);
		cout << flush;
	}
	return 0;
}