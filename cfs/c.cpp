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

vector<int> ps;
unordered_map<ll, ll> mp;

void sieve() {
	int n = 1e6;
	vector<bool> isp(n + 1, 1);
	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) isp[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
		if (isp[i]) ps.pb(i);
}

ll phi(ll n, ll k) {
	if (k == 0) return n;
	ll key = n * 1e8 + k;
	if (mp.contains(key)) return mp[key];
	return mp[key] = phi(n, k - 1) - phi(n / ps[k - 1], k - 1);
}

void solve(int test_case [[maybe_unused]]) {
	int N = 1e9;
	// cin >> N;
	sieve();

	ll l = 0, r = 10, pi = 4;
	int idx = N;
	while (pi < N) {
		l = r, r *= 10;
		idx = N - pi;
		int t = sqrt(r);
		int s = ub(ps.begin(), ps.end(), t) - ps.begin();
		cerr << t << ' ';
		pi = phi(r, s) + s - 1;
		cerr << pi << ' ' << r << nl;
	}
	cout << idx << ' ' << pi << ' ' << l << ' ' << r << nl;
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