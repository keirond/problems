#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mci = map<char, int>;
using vpii = vector<pii>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
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

// --------------------------------------------------------------------------
// Read methods (only Leetcode)

template <typename T> void __cin(stringstream &ss, T &value) { ss >> value; }

void __cin(stringstream &ss, char &value) {
	char c;
	ss >> c >> value >> c;
}

void __cin(stringstream &ss, string &value) {
	char c;
	ss >> c, getline(ss, value, '"');
}

template <typename T, typename V>
void __cin(stringstream &ss, pair<T, V> &values) {
	char c;
	ss >> c;
	__cin(ss, values.first);
	ss >> c;
	__cin<V>(ss, values.second);
	ss >> c;
}

template <typename T> void __cin(stringstream &ss, vector<T> &values) {
	char c;
	ss >> c;

	while (ss.peek() != ']') {
		T value;
		__cin(ss, value);
		values.push_back(value);
		ss >> c;
		if (c == ']') break;
	}
}

void __read() {}

template <typename T, typename... V> void __read(T &t, V &...v) {
	string str;
	getline(cin, str);
	stringstream ss(str);
	__cin(ss, t);
	__read(v...);
}

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

void solve(int test_case [[maybe_unused]]) {}

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

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************