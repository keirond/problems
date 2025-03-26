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

	STree(int n) : n(n), tree(n << 2, -1) {}

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
		tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
	}

	void update(int x, int y) { update(1, 0, n - 1, x, y); }

	int query(int node, int l, int r, int ql, int qr) {
		if (ql > r || qr < l) return -1;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return max(query(node << 1, l, m, ql, qr),
				   query(node << 1 | 1, m + 1, r, ql, qr));
	}

	int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve(int test_case [[maybe_unused]]) {
	int Q;
	cin >> Q;
	vector<tuple<string, int, int>> queries;
	vector<int> t;
	while (Q--) {
		string op;
		int x, y;
		cin >> op >> x >> y;
		queries.push_back({op, x, y});
		t.push_back(x);
	}

	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());

	int n = t.size();
	vector<set<int>> mp(n);

	auto _rank = [&](int v) -> int {
		return lower_bound(t.begin(), t.end(), v) - t.begin();
	};

	STree st(n);

	for (auto [op, x, y] : queries) {
		int rank = _rank(x);
		if (op == "add") {
			mp[rank].insert(y);
			st.update(rank, *(--mp[rank].end()));
		} else if (op == "remove") {
			mp[rank].erase(y);
			st.update(rank, mp[rank].size() ? *(--mp[rank].end()) : -1);
		} else {
			if (rank == n - 1)
				cout << -1 << '\n';
			else {
				int l = rank + 1, r = n - 1;
				while (l < r) {
					int m = l + (r - l >> 1);
					if (st.query(l, m) > y)
						r = m;
					else
						l = m + 1;
				}
				if (mp[l].size()) {
					auto ity = mp[l].upper_bound(y);
					if (ity == mp[l].end())
						cout << -1 << '\n';
					else
						cout << t[l] << ' ' << *ity << '\n';
				} else
					cout << -1 << '\n';
			}
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