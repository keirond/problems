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

struct STree {
	int n;
	vector<int> tree;

	STree(int n) : n(n), tree(n << 1, 0) {}

	void update(int i, int val) {
		i += n;
		tree[i] = max(tree[i], val);
		for (; i > 0; i >>= 1) {
			tree[i >> 1] = max(tree[i], tree[i ^ 1]);
		}
	}

	int query(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ans = max(ans, tree[l++]);
			if (!(r & 1)) ans = max(ans, tree[r--]);
		}
		return ans;
	}
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<vector<int>> nums(N, vector<int>(3, 0));
	for(int j=0; j<3; ++j) {
		for(int i=0; i<N; ++i) {
			int d; cin >> d;
			nums[i][j] = d;
		}
	}
	sort(nums.begin(), nums.end(), [](auto &x, auto &y) { return x[0] > y[0]; });

	vector<int> t;
	for (int i = 0; i < N; ++i) {
		t.push_back(nums[i][1]);
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());

	auto _get = [&](int v) -> int {
		return lower_bound(t.begin(), t.end(), v) - t.begin();
	};

	info(nums);
	STree st(N);
	vector<vector<int>> temp;
	int prev = INT_MAX;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if(nums[i][0] < prev) {
			for(auto &d: temp) {
				st.update(d[1], d[2]);
			}
			temp.clear();
		}
		prev = nums[i][0]; 
		int rank = _get(nums[i][1]);
		if (st.query(rank + 1, N - 1) > nums[i][2]) ans++;
		else {
			nums[i][1] = rank;
			temp.push_back(nums[i]);
		}
	}
	cout <<  ans << '\n';
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