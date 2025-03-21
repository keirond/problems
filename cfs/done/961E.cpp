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

struct FTree {
	int n;
	vector<int> ft;

	FTree(int n) : n(n), ft(n + 1) {}

	void update(int i, int val) {
		for (; i <= n; i += i & -i) ft.at(i) += val;
	}

	int query(int i) {
		int ans = 0;
		for (; i > 0; i -= i & -i) ans += ft.at(i);
		return ans;
	}

	int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> nums;
	vector<pair<int, int>> t;
	for (int i = 0; i < N; ++i) {
		int d;
		cin >> d;
		nums.push_back(d);
		t.push_back({d, i + 1});
	}

	sort(t.begin(), t.end());

	info(nums, t);
	FTree ft(N);

	long long ans = 0;
	int j = N - 1;
	for (int i = N; i >= 1; --i) {
		while (j >= 0 && t[j].first >= i) {
			ft.update(t[j].second, 1);
			j--;
		}
		info(ft.ft);
		// a[ho] >= i
		// a[i] >= ho (count ho)
		if (nums[i - 1] >= i) ans += ft.query(i + 1, min(N, nums[i - 1]));
	}
	cout << ans << '\n';
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