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

const int A = 2;
struct Trie {
	Trie* link[A];
	bool end;

	Trie() {
		fill(link, link + A, nullptr);
		end = 0;
	}

	void insert(int x) {
		auto u = this;
		for (int i = 0; i < 31; i++) {
			int d = x >> i & 1;
			if (!u->link[d]) u->link[d] = new Trie();
			u = u->link[d];
			x >>= 1;
		}
		u->end = 1;
	}

	bool query(int x) {
		auto u = this;
		for (int i = 0; i < 31; i++) {
			int d = x >> i & 1;
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