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
		for (; i <= n; i += i & -i) ft[i] += val;
	}

	int query(int i) {
		int ans = 0;
		for (; i > 0; i -= i & -i) ans += ft[i];
		return ans;
	}

	int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> nums(N), t;
	for (auto &d : nums) {
		cin >> d;
		t.push_back(d);
	}

	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());

	auto _get = [&](int v) -> int {
		return lower_bound(t.begin(), t.end(), v) - t.begin() + 1;
	};

	vector<int> rlow(N), lhigh(N);

	FTree ft(N);
	for (int i = N - 1; i >= 0; --i) {
		int rank = _get(nums[i]);
		rlow[i] = ft.query(1, rank - 1);
		ft.update(rank, 1);
	}

	long long ans = 0;
	ft = FTree(N);
	for (int i = 0; i < N; ++i) {
		int rank = _get(nums[i]);
		lhigh[i] = ft.query(rank + 1, N);
		ft.update(rank, 1);
		ans += (long long)rlow[i] * lhigh[i];
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