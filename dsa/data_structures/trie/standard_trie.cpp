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
struct Trie {
	Trie* link[A];
	bool end;

	Trie() {
		fill(link, link + A, nullptr);
		end = 0;
	}

	void insert(string& s) {
		auto u = this;
		for (char c : s) {
			int d = c - 'a';
			if (!u->link[d]) u->link[d] = new Trie();
			u = u->link[d];
		}
		u->end = 1;
	}

	bool query(string& s) {
		auto u = this;
		for (char c : s) {
			int d = c - 'a';
			if (!u->link[d]) return 0;
			u = u->link[d];
		}
		return u->end;
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