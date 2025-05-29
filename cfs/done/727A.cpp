#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

bool call(int B, ll c, vector<int> &st) {
	if (c > B) return false;
	st.push_back(c);
	if (c == B) return true;
	if (call(B, c * 2, st)) return true;
	if (call(B, c * 10 + 1, st)) return true;
	st.pop_back();
	return false;
}

void solve(int test_case [[maybe_unused]]) {
	int A, B;
	cin >> A >> B;

	vector<int> ans;
	if (call(B, A, ans)) {
		cout << "YES" << nl;
		cout << ans.size() << nl;
		for (int d : ans) cout << d << ' ';
		cout << nl;
	} else
		cout << "NO" << nl;
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

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