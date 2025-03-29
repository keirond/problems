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

long long pown(long long a, long long d, long long n) {
	long long ans = 1;
	a %= n;
	while (d) {
		if (d & 1) ans = (__int128)ans * a % n;
		a = (__int128)a * a % n;
		d >>= 1;
	}
	return ans;
}

bool miller_test(int a, long long d, long long n, int s) {
	long long x = pown(a, d, n);
	if (x == 1 || x == n - 1) return true;
	for (int i = 0; i < s - 1; ++i) {
		x = (__int128)x * x % n;
		if (x == n - 1) return true;
	}
	return false;
}

bool is_prime(long long n) {
	if (n < 2) return false;
	if (n & 2 == 0) return n == 2;

	long long d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		++s;
		d >>= 1;
	}

	vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (long long a : bases) {
		if (a >= n) break;
		if (!miller_test(a, d, n, s)) return false;
	}
	return true;
}

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<int> primes(N + 1);
	primes[0] = primes[1] = 0;
	for (int i = 2; i * i <= N; ++i) {
		if (primes[i]) {
			for (int j = i * i; j <= N; j += i) primes[j] = 0;
		}
	}

	vector<int> temp;
	for (int i = 0; i <= N; ++i) {
		if (primes[i]) temp.push_back(i);
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