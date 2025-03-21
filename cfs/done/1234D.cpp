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
	vector<int> ft[26];
	string str;

	FTree(string str) {
		this->n = str.size();
		for (int i = 0; i < 26; ++i) this->ft[i].assign(n + 1, 0);
		this->str = str;
		for (int i = 0; i < n; ++i) build(i + 1, str[i] - 'a');
	}

	void build(int i, int ic) {
		for (; i <= n; i += i & -i) ft[ic][i]++;
	}

	void assign(int i, char c) {
		update(i, str[i - 1] - 'a', c - 'a');
		str[i - 1] = c;
	}

	void update(int i, int oc, int nc) {
		for (; i <= n; i += i & -i) {
			ft[oc][i]--;
			ft[nc][i]++;
		}
	}

	int _query(int i, int ic) {
		int ans = 0;
		for (; i > 0; i -= i & -i) ans += ft[ic][i];
		return ans;
	}

	int query(int l, int r) {
		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			int t = _query(r, i) - _query(l - 1, i);
			ans += t > 0 ? 1 : 0;
		}
		return ans;
	}
};

void solve(int test_case [[maybe_unused]]) {
	string S;
	cin >> S;

	FTree ft(S);

	int N;
	cin >> N;
	while (N--) {
		int op, l, r;
		char c;
		cin >> op;
		if (op == 1) {
			cin >> l >> c;
			ft.assign(l, c);
		} else if (op == 2) {
			cin >> l >> r;
			cout << ft.query(l, r) << '\n';
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