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

int n;
vector<int> tree;

void update(int node, int l, int r, int i, int level, int val) {
	if (l == r) {
		tree[node] = val;
		return;
	}
	int m = l + (r - l >> 1);
	if (i <= m)
		update(node << 1, l, m, i, level - 1, val);
	else
		update(node << 1 | 1, m + 1, r, i, level - 1, val);
	if (level % 2)
		tree[node] = tree[node << 1] | tree[node << 1 | 1];
	else
		tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

void update(int i, int val) { update(1, 0, (1 << n) - 1, i, n, val); }

void solve(int test_case [[maybe_unused]]) {
	int N, Q;
	cin >> N >> Q;

	n = N;
	tree.assign((1 << n) << 2, 0);
	for (int i = 0; i < (1 << N); ++i) {
		int d;
		cin >> d;
		update(i, d);
	}

	while (Q--) {
		int p, b;
		cin >> p >> b;
		update(p - 1, b);
		cout << tree[1] << '\n';
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