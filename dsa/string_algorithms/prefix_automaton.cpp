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

vector<int> pi_gen(string &str) {
	int n = str.size();
	vector<int> pi(n);

	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}
		if (str[i] == str[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<vector<int>> aut;
void automaton_gen(string str) {
	str += '#';
	int n = str.size();
	vector<int> pi = pi_gen(str);
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < 26; c++) {
			if (i > 0 && 'a' + c != str[i])
				aut[i][c] = aut[pi[i - 1]][c];
			else
				aut[i][c] = i + ('a' + c == str[i]);
		}
	}
}

void solve(int test_case [[maybe_unused]]) {
	string txt, pat;
	cin >> txt >> pat;

	int n = txt.size(), m = pat.size();
	aut.assign(m + 1, vector<int>(26));
	automaton_gen(pat);

	for (int i = 0, j = 0; i < n; i++) {
		j = aut[j][txt[i] - 'a'];
		if (j == m) {
			cout << i - m + 1 << ' ';
		}
	}
	cout << nl;
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