#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<vi>;
using vll = vector<vl>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mci = map<char, int>;
using si = set<int>;
using sc = set<char>;
using di = deque<int>;
using dpii = deque<pii>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

#define FOR(a, b, c) for (int a = (b); (a) <= (c); ++(a))
#define FORd(a, b, c) for (int a = (b); (a) >= (c); --(a))
#define FORsq(a, b, c) for (int a = (b); (a) * (a) <= (c); ++(a))
#define FORsqd(a, b, c) for (int a = (b); (a) * (a) >= (c); --(a))
#define FORc(a, b, c) for (char a = (b); (a) <= (c); ++(a))
#define EACH(a, b) for (auto &a : (b))
#define REP(i, n) FOR(i, 0, n - 1)
#define REPd(i, n) FORd(i, n - 1, 0)

constexpr double EPS [[maybe_unused]] = 1e-9;
constexpr double PI [[maybe_unused]] = 3.14159265358979323846;
constexpr int MOD [[maybe_unused]] = static_cast<int>(1e9 + 7);
constexpr int INF [[maybe_unused]] = INT_MAX;
constexpr ll LINF [[maybe_unused]] = LLONG_MAX;
constexpr char nl [[maybe_unused]] = '\n';

// --------------------------------------------------------------------------

template <class T> using max_heap = priority_queue<T>;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

string to_upper(string a) {
	return transform(a.begin(), a.end(), a.begin(), ::toupper), a;
}
string to_lower(string a) {
	return transform(a.begin(), a.end(), a.begin(), ::tolower), a;
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
	vector<long long> tree, lazy;
	vector<bool> pending;

	STree(vector<int> &nums) {
		n = nums.size();
		tree.assign(n << 2, 0);
		lazy.assign(n << 2, 0);
		pending.assign(n << 2, 0);
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
		if (pending[node]) {
			tree[node] = lazy[node] * (r - l + 1);
			if (l != r) {
				lazy[node << 1] = lazy[node];
				lazy[node << 1 | 1] = lazy[node];
				pending[node << 1] = pending[node << 1 | 1] = true;
			}
			lazy[node] = 0;
			pending[node] = false;
		}
	}

	void update(int node, int l, int r, int ql, int qr, int val) {
		push(node, l, r);
		if (qr < l || ql > r) return;
		if (ql <= l && r <= qr) {
			lazy[node] = val;
			push(node, l, r);
			return;
		}
		int m = l + (r - l >> 1);
		update(node << 1, l, m, ql, qr, val);
		update(node << 1 | 1, m + 1, r, ql, qr, val);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	long long query(int node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (qr < l || ql > r) return 0;
		if (ql <= l && r <= qr) return tree[node];
		int m = l + (r - l >> 1);
		return query(node << 1, l, m, ql, qr) +
			   query(node << 1 | 1, m + 1, r, ql, qr);
	}

	void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

	long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N, cin.ignore();
	vector<int> nums;
	for (int i = 0; i < N; ++i) {
		int val;
		cin >> val;
		nums.push_back(val);
	}

	auto stree = STree(nums);

	int Q;
	cin >> Q, cin.ignore();
	while (Q--) {
		string str;
		getline(cin, str);
		stringstream ss(str);
		int val;
		vector<int> t;
		while (ss >> val) {
			t.push_back(val);
		}
		if (t.size() == 2) {
			if (t[0] <= t[1])
				cout << stree.query(t[0], t[1]) << nl;
			else
				cout << (int)min(stree.query(t[0], N - 1), stree.query(0, t[1]))
					 << nl;
		} else if (t.size() == 3) {
			if (t[0] <= t[1])
				stree.update(t[0], t[1], t[2]);
			else {
				stree.update(t[0], N - 1, t[2]);
				stree.update(0, t[1], t[2]);
			}
		}
	}
}

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