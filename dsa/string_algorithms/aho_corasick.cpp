#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct AC {
	int A = 26, P = 0;
	vector<vector<int>> next;
	vector<int> link, out_link;
	vector<vector<int>> out;

	int add_node() {
		nxt.emplace_back(A, 0);
		link.emplace_back(0);
		out_link.emplace_back(0);
		out.emplace_back();
		return nxt.size() - 1;
	}

	int insert(string &s) {
		int u = 0;
		for (char c : s) {
			int d = c - 'a';
			if (!next[u][d]) next[u][d] = add_node();
			u = next[u][d];
		}
		out[u].pb(P);
		return P++;
	}

	void compute() {
		deque<int> q;
		for (q.pb(0); !q.empty();) {
			int u = q.front();
			q.pp();
			for (int c = 0; c < A; ++c) {
				int v = next[u][c];
				if (!v)
					next[u][c] = next[link[u]][c];
				else {
					link[v] = u ? next[link[u]][c] : 0;
					out_link[v] =
						out[link[v]].empty() ? out_link[link[v]] : link[v];
					q.pb(v);
				}
			}
		}
	}
};

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<string> V(N);
	for (string &d : V) cin >> d;

	sort(all(V));
	V.erase(unique(all(V)), V.end());

	int S;
	cin >> S;
	int n = S.size();
	vector<int> dp(n, n + 10);
	int u = 0;
	for (int i = 0, u = 0; i < n; i++) {
		char c = S[i];
	}
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************