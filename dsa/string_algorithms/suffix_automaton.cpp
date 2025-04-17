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
	int last = 0, sz = 0;
	vector<int> link, len, count;
	vector<vector<int>> next;

	SA() { add_node(); }

	int add_node() {
		len.emplace_back();
		next.emplace_back(A, -1);
		link.emplace_back(-1);
		count.emplace_back();
		return sz++;
	}

	void extend(char c) {
		int u = add_node();
		int d = c - 'a', p = last;
		len[u] = len[p] + 1;
		count[u] = 1;

		while (p != -1 && next[p][d] == -1) {
			next[p][d] = u;
			p = link[p];
		}

		if (p == -1) {
			link[u] = 0;
		} else {
			int q = next[p][d];
			if (len[p] + 1 == len[q]) {
				link[u] = q;
			} else {
				int clone = add_node();
				len[clone] = len[p] + 1;
				next[clone] = next[q];
				link[clone] = link[q];
				while (p != -1 && next[p][d] == q) {
					next[p][d] = clone;
					p = link[p];
				}
				link[u] = link[q] = clone;
			}
		}
		last = u;
	}

	bool contains(const string &ss) {
		int u = 0;
		for (char c : ss) {
			int d = c - 'a';
			if (next[u][d] == -1) return false;
			u = next[u][d];
		}
		return true;
	}

	ll distinct_substring() {
		ll ans = 0;
		for (int i = 1; i < sz; i++) {
			ans += len[i] - len[link[i]];
		}
		return ans;
	}

	void count_occurrence() {
		vector<int> order(sz);
		iota(all(order), 0);
		sort(all(order), [&](int a, int b) { return len[a] > len[b]; });

		for (int d : order) {
			if (link[d] != -1) {
				count[link[d]] += count[d];
			}
		}
	}

	int longest_common_substring(const string &b) {
		int u = 0, l = 0, ans = 0;
		for (char c : b) {
			int d = c - 'a';
			if (next[u][d] != -1) {
				l++;
				u = next[u][d];
			} else {
				while (u != -1 && next[u][d] == -1) {
					u = link[u];
				}
				if (u == -1) {
					l = 0;
					u = 0;
				} else {
					l = len[u] + 1;
					u = next[u][d];
				}
			}
			ans = max(ans, l);
		}
		return ans;
	}
};

void solve(int test_case [[maybe_unused]]) {
	string s = "abracadabra";
	cout << s << nl;

	SA sa;
	for (char c : s) sa.extend(c);

	cout << sa.contains("cada") << nl;
	cout << sa.contains("abc") << nl;
	cout << sa.distinct_substring() << nl;
	sa.count_occurrence();
	for (int d : sa.count) {
		cout << d << ' ';
	}
	cout << nl;
	cout << sa.longest_common_substring("bbracxdabradascv") << nl;
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