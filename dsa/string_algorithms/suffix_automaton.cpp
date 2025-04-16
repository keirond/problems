#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define up upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

const int A = 26;
struct SA {
	int last, sz = 0;
	vector<int> len, link, first_pos;
	vector<vector<int>> next;

	int add_node() { next.emplace_back(A, 0); }

	void extend(char c) {
		int d = c - 'a';
		int u = last;
		if (next[u][d]) {
			int v = next[u][d];
			if (len[v] == len[u] + 1) {
				last = v;
				return;
			}

			int clone = sz++;
			for (int i = 0; i < A; i++) {
				next[clone][i] = next[v][i];
			}
			len[clone] = len[u] + 1;
			link[v] = clone;

			while (u != 0 && next[u][d] == v) {
				next[u][d] = clone;
				u = link[u];
			}
			return;
		}

		int cur = sz++;
		len[cur] = len[last] + 1;
		first_pos[cur] = len[cur];
		u = last;
		while (u != 0 && !next[u][d]) {
			next[u][d] = cur;
			u = link[u];
		}

		if (!u)
			link[cur] = 0;
		else {
			int v = next[u][d];
			if (len[u] + 1 == len[v])
				link[cur] = v;
			else {
				int clone = sz++;
				for (int i = 0; i < A; i++) {
					next[clone][i] = next[v][i];
				}
				len[clone] = len[u] + 1;

				while (u != 0 && next[u][d] == v) {
					next[u][d] = clone;
					u = link[u];
				}

				link[v] = link[cur] = clone;
			}
		}
		last = cur;
	}
};

void solve(int test_case [[maybe_unused]]) {}

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