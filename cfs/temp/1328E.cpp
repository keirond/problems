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

int LOG = 20;
vector<vector<int>> adj;
vector<int> depth;
vector<vector<int>> dp;

void dfs(int u, int p) {
	dp[u][0] = p;
	for (int i = 1; i < LOG; i++) {
		dp[u][i] = dp[dp[u][i - 1]][i - 1];
	}

	for (int v : adj[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
}

int lift(int u, int k) {
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			u = dp[u][i];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = lift(u, depth[u] - depth[v]);

	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

void solve(int test_case [[maybe_unused]]) {
	int N, Q;
	cin >> N >> Q;
	adj.resize(N);
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u - 1].pb(v - 1);
	}

	depth.resize(N);
	dp.assign(N, vector<int>(LOG));
	dfs(0, 0);

	string str;
	stringstream ss;
	getline(cin, str);
	while (Q--) {
		getline(cin, str);
		ss.clear();
		ss.str(str);

		int t;
		vector<int> ks;
		int deepest = 0;
		while (ss >> t) {
			int u = t - 1;
			ks.pb(u);
			if (depth[u] > depth[deepest]) {
				deepest = u;
			}
		}

		info(ks, deepest);
		string ans = "YES";
		for (int v : ks) {
			if (v == 0) continue;
			int u = dp[v][0];
			if (lca(u, deepest) != u) {
				ans = "NO";
				break;
			}
		}
		cout << ans << nl;
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

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************