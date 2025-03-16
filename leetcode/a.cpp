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

vector<int> productQueries(int N, vector<vector<int>> &queries) {
	int mod = 1e9 + 7;

	vector<int> nums;
	int t = 10;
	while (N > 0 && t >= 0) {
		if (N >= (1 << t)) {
			nums.push_back(1 << t);
			N -= 1 << t;
		}
		t--;
	}
	reverse(nums.begin(), nums.end());
	dbg(nums)

		int n = nums.size();
	vector<int> stree(2 * n, 1);

	for (int i = 0; i < n; ++i) {
		stree[i + n] = nums[i];
	}
	for (int i = n - 1; i > 0; --i) {
		stree[i] = ((long long)stree[i * 2] * stree[i * 2 + 1]) % mod;
	}

	vector<int> ans;
	for (auto &d : queries) {
		int l = d[0], r = d[1];
		int val = 1;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l & 1) val = ((long long)val * stree.at(l++)) % mod;
			if (!(r & 1)) val = ((long long)val * stree.at(r--)) % mod;
		}
		ans.push_back(val);
	}
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	string str;
	stringstream ss;

	int n;
	getline(cin, str);
	ss.clear();
	ss.str(str);
	__read(ss, n);

	vector<vector<int>> nums;
	getline(cin, str);
	ss.clear();
	ss.str(str);
	__read(ss, nums);

	vector<int> ans = productQueries(n, nums);
	cout << '[';
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) cout << ',';
		cout << ans[i];
	}
	cout << ']';
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