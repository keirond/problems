#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound

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

void solve(int test_case [[maybe_unused]]) {
	int n = 1e9;
	int m = sqrt(n);

	int cnt = 0;

	vector<int> ps;
	vector<bool> isp(m + 1, 1);
	for (int i = 2; i * i <= m; i++) {
		if (isp[i]) {
			if (cnt++ % 500 == 0) cout << i << nl;
			ps.pb(i);
			for (int j = i * i; j <= m; j += i) isp[j] = 0;
		}
	}

	for (int l = 0; l <= n; l += m) {
		int r = min(l + m, n + 1);
		vector<bool> nisp(r - l, 1);
		for (int p : ps) {
			ll start = min(p * p, (l + p - 1) / p * p);
			if (start >= r) break;
			for (int j = start; j < r; j += p) nisp[j] = 0;
		}
		for (int i = 0; i < r - l; i++) {
			if (nisp[i]) {
				if (cnt++ % 500 == 0) cout << i + l << nl;
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