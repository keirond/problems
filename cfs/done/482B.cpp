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
	vector<int> tree, lazy;

	STree(int n) : n(n), tree(n << 2), lazy(n << 2) {}

	void push(int node, int l, int r) {
		if (lazy[node]) {
			for (int i = 0; i < 31; ++i) {
				if (lazy[node] >> i & 1) {
					tree[node] |= 1 << i;
				}
			}
			if (l != r) {
				lazy[node << 1] |= lazy[node];
				lazy[node << 1 | 1] |= lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update(int node, int l, int r, int ql, int qr, int val) {
		push(node, l, r);
		if (ql > r || qr < l) return;
		if (ql <= l && r <= qr) {
			lazy[node] |= val;
			push(node, l, r);
			return;
		}
		int m = l + (r - l >> 1);
		update(node << 1, l, m, ql, qr, val);
		update(node << 1 | 1, m + 1, r, ql, qr, val);
		tree[node] = tree[node << 1] & tree[node << 1 | 1];
	}

	void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

	int query(int node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (ql > r || qr < l) return ~0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) &
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;

	STree st(N);
	vector<vector<int>> constraints;
	for (int i = 0; i < M; ++i) {
		int l, r, q;
		cin >> l >> r >> q;
		st.update(l - 1, r - 1, q);
		constraints.push_back({l - 1, r - 1, q});
	}

	for (auto &d : constraints) {
		if (st.query(d[0], d[1]) != d[2]) {
			cout << "NO" << nl;
			return;
		}
	}
	cout << "YES" << nl;
	for (int i = 0; i < N; ++i) {
		if (i != 0) cout << ' ';
		cout << st.query(i, i);
	}
	cout << nl;
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