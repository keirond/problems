#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr char nl [[maybe_unused]] = '\n';
#define pb push_back

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
	int N, M;
	cin >> N >> M;

	int CN = 1e7;
	vector<int> spf(CN + 1);
	iota(spf.begin(), spf.end(), 0);
	for (int i = 2; i * i <= CN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j <= CN; j += i) {
				if (spf[j] == j) spf[j] = i;
			}
		}
	}

	vector<int> A, B;
	unordered_map<int, int> mp;
	while (N--) {
		int d;
		cin >> d;
		A.push_back(d);
		while (d != 1) {
			mp[spf[d]]++;
			d /= spf[d];
		}
	}
	while (M--) {
		int d;
		cin >> d;
		B.push_back(d);
		while (d != 1) {
			mp[spf[d]]--;
			d /= spf[d];
		}
	}

	vector<int> nA, nB;
	for (int d : A) {
		unordered_map<int, int> t;
		int e = d;
		while (d != 1) {
			t[spf[d]]++;
			d /= spf[d];
		}
		info(t);
		for (auto [k, v] : t) {
			while (v > max(mp[k], 0)) {
				e /= k;
				v--;
			}
			mp[k] -= v;
		}
		if (e != 1) nA.push_back(e);
	}

	for (int d : B) {
		unordered_map<int, int> t;
		int e = d;
		while (d != 1) {
			t[spf[d]]++;
			d /= spf[d];
		}
		for (auto [k, v] : t) {
			while (v > max(-mp[k], 0)) {
				e /= k;
				v--;
			}
			mp[k] += v;
		}
		if (e != 1) nB.push_back(e);
	}
	if (nA.empty()) nA.push_back(1);
	if (nB.empty()) nB.push_back(1);

	cout << nA.size() << ' ' << nB.size() << nl;
	for (auto d : nA) cout << d << ' ';
	cout << nl;
	for (auto d : nB) cout << d << ' ';
	cout << nl;
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