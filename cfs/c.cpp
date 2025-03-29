#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

ll mult(ll a, ll d, ll m) { return (__int128)a * d % m; }

ll f(ll a, ll c, ll m) { return (mult(a, a, m) + c) % m; }

ll rho(ll n) {
	if (n % 2 == 0) return 2;
	ll u = rand() % (n - 2) + 2, v = u;
	ll c = rand() % (n - 1) + 1, g = 1;
	while (g == 1) {
		u = f(u, c, n);
		v = f(v, c, n);
		v = f(v, c, n);
		g = gcd(abs(u - v), n);
	}
	if (g == n) return rho(n);
	return g;
}

ll pown(ll a, ll d, ll n) {
	ll ans = 1;
	a %= n;

	while (d) {
		if (d & 1) ans = (__int128)ans * a % n;
		a = (__int128)a * a % n;
		d >>= 1;
	}
	return ans;
}

bool miller_test(ll a, ll d, ll n, int s) {
	ll x = pown(a, d, n);
	if (x == 1 || x == n - 1) return true;

	for (int i = 0; i < s - 1; ++i) {
		x = (__int128)x * x % n;
		if (x == n - 1) return true;
	}
	return false;
}

bool is_prime(ll n) {
	if (n < 2) return false;
	if (n % 2 == 0) return n == 2;

	ll d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		s++;
		d >>= 1;
	}

	vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (ll a : bases) {
		if (a >= n) break;
		if (!miller_test(a, d, n, s)) return false;
	}
	return true;
}

void factorize(ll n, vector<ll> &ans) {
	if (n == 1) return;
	if (is_prime(n)) {
		ans.push_back(n);
		return;
	}

	ll d = rho(n);
	factorize(d, ans);
	factorize(n / d, ans);
}

void solve(int test_case [[maybe_unused]]) {
	int Q;
	cin >> Q;
	while (Q--) {
		ll N;
		cin >> N;
		vector<ll> ans;
		factorize(N, ans);
		info(ans);
		cout << ans.size();
		for (auto d : ans) {
			cout << ' ' << d;
		}
		cout << nl;
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