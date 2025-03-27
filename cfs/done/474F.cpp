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
	vector<pair<int, int>> tree;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(n << 2, {1, 0});
		build(nums, 1, 0, n - 1);
	}

	void build(vector<int> &nums, int node, int l, int r) {
		if (l == r) {
			tree[node] = {nums[l], 1};
			return;
		}
		int m = l + (r - l >> 1);
		build(nums, node << 1, l, m);
		build(nums, node << 1 | 1, m + 1, r);
		auto t1 = tree[node << 1], t2 = tree[node << 1 | 1];
		tree[node].first = gcd(t1.first, t2.first);
		if (t1.first == tree[node].first) {
			tree[node].second += t1.second;
		}
		if (t2.first == tree[node].first) {
			tree[node].second += t2.second;
		}
	}

	pair<int, int> query(int node, int l, int r, int ql, int qr) {
		if (ql > r || qr < l) return {-1, 0};
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		auto t1 = query(node << 1, l, m, ql, qr);
		auto t2 = query(node << 1 | 1, m + 1, r, ql, qr);

		if (t1.first == -1) return t2;
		if (t2.first == -1) return t1;

		int vf = gcd(t1.first, t2.first), vs = 0;
		if (t1.first == vf) {
			vs += t1.second;
		}
		if (t2.first == vf) {
			vs += t2.second;
		}
		return {vf, vs};
	}

	int query(int l, int r) { return query(1, 0, n - 1, l, r).second; }
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> nums(N);
	for (auto &d : nums) cin >> d;
	STree st(nums);

	int Q;
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << r - l + 1 - st.query(l - 1, r - 1) << nl;
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