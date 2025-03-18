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
	vector<pair<long long, long long>> tree;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(n << 2, {0, 0});
		build(nums, 1, 0, n - 1);
	}

	void apply(int i) {
		tree[i].first = tree[i << 1].first + tree[i << 1 | 1].first;
		tree[i].second = max(tree[i << 1].second, tree[i << 1 | 1].second);
	}

	void build(vector<int> &nums, int node, int l, int r) {
		if (l == r) {
			tree[node] = {nums[l], nums[l]};
			return;
		}
		int m = l + (r - l >> 1);
		build(nums, node << 1, l, m);
		build(nums, node << 1 | 1, m + 1, r);
		apply(node);
	}

	void update(int node, int l, int r, int i, int val) {
		if (l == r) {
			tree[node] = {val, val};
			return;
		}
		int m = l + (r - l >> 1);
		if (i <= m)
			update(node << 1, l, m, i, val);
		else
			update(node << 1 | 1, m + 1, r, i, val);
		apply(node);
	}

	void update(int i, int val) { update(1, 0, n - 1, i, val); }

	void update_mod(int node, int l, int r, int ql, int qr, int mod) {
		if (tree[node].second < mod) return;
		if (qr < l || ql > r) return;
		if (l == r) {
			tree[node].first %= mod;
			tree[node].second %= mod;
			return;
		}
		int m = l + (r - l >> 1);
		update_mod(node << 1, l, m, ql, qr, mod);
		update_mod(node << 1 | 1, m + 1, r, ql, qr, mod);
		apply(node);
	}

	void update_mod(int l, int r, int mod) {
		update_mod(1, 0, n - 1, l, r, mod);
	}

	long long query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node].first;
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) +
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}
	long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve(int test_case [[maybe_unused]]) {
	int N, M;
	cin >> N >> M;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		int val;
		cin >> val;
		nums[i] = val;
	}
	cin.ignore();

	auto stree = STree(nums);

	while (M--) {
		vector<int> t;
		string str;
		getline(cin, str);
		stringstream ss(str);
		int val;
		while (ss >> val) t.push_back(val);
		if (t[0] == 1) {
			cout << stree.query(t[1] - 1, t[2] - 1) << nl;
		} else if (t[0] == 2) {
			stree.update_mod(t[1] - 1, t[2] - 1, t[3]);
		} else if (t[0] == 3) {
			stree.update(t[1] - 1, t[2]);
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