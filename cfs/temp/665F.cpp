#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

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

const int MAXV = 1e6 + 1;
const int MAXP = 7;
const int MAXK = 50;
const int MAXN = 2 * 3 * 5 * 7 * 11 * 13 * 17;

vector<int> ps, pi(MAXV), prod(MAXP);
vector<vector<int>> dp(MAXK, vector<int>(MAXN));

void gen() {
	bitset<MAXV> isp;
	isp.set();

	for (int i = 2; i * i < MAXV; i++) {
		if (isp[i]) {
			for (int j = i * i; j < MAXV; j += i) isp[j] = 0;
		}
	}

	for (int i = 2; i < MAXV; i++) {
		if (isp[i]) ps.pb(i);
		pi[i] = ps[i - 1] + ps[i];
	}

	prod[0] = ps[0];
	for (int i = 1; i < MAXP; i++) prod[i] = prod[i - 1] * ps[i];

	for (int i = 0; i < MAXN; i++) dp[0][i] = i;
	for (int i = 0; i < MAXK; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = dp[i - 1][j] - dp[i - 1][j / ps[i - 1]];
		}
	}
}

ll phi(ll n, ll k) {
	if (!k) return n;
	if (k < MAXK && n < MAXN) return dp[k][n];
	if (k < MAXP)
		return dp[k][n % prod[k - 1]] + n / prod[k - 1] * dp[k][prod[k - 1]];

	int p = ps[k - 1];
	if (n < MAXV && p * p >= n) return pi[n] - k + 1;
	if (n < MAXV && p * p * p >= n) {
		int s = sqrt(n);
		ll ans = pi[n] - k + 1;
		for (int i = k; i < pi[s]; i++) {
			ans += pi[n / ps[i]] - i;
		}
		return ans;
	}
	return phi(n, k - 1) - phi(n / ps[k - 1], k - 1);
}

ll count(ll n) {
	if (n < MAXV) return pi[n];

	ll s = sqrt(n), c = cbrt(n);

	ll ans = phi(n, pi[c]) + pi[c] - 1;
	for (int i = pi[c]; i < pi[s]; i++) ans -= count(n / ps[i]) - i;
	return ans;
}

void solve(int test_case [[maybe_unused]]) {
	ll N;
	cin >> N;

	gen();
	cout << count(1e9) << nl;
	// int s = sqrt(N), c = cbrt(N);
	// ll ans = ub(all(ps), c) - ps.begin();
	// for (int i = 0; i < pi[s]; i++) {
		// ans += count(N / ps[i]) - count(ps[i]);
	// }
	// cout << ans << nl;
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

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************