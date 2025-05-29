#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int N;
	cin >> N;
	vector<string> names(N);
	vector<vector<int>> adj(26);
	vector<int> idr(26);
	for (auto &d : names) cin >> d;
	for (int i = 1; i < N; i++) {
		string prev = names[i - 1], curr = names[i];
		int j = 0;
		while (j < prev.size() && j < curr.size() && prev[j] == curr[j]) j++;
		if (j < prev.size() && j < curr.size()) {
			adj[curr[j] - 'a'].push_back(prev[j] - 'a');
			idr[prev[j] - 'a']++;
		} else if (j < prev.size()) {
			cout << "Impossible" << nl;
			return;
		}
	}

	vector<int> ans;
	deque<int> dq;
	for (int i = 0; i < 26; i++) {
		if (!idr[i]) dq.push_back(i);
	}

	while (!dq.empty()) {
		int u = dq.front();
		dq.pop_front();
		ans.push_back(u);
		for (int v : adj[u]) {
			if (!--idr[v]) dq.push_back(v);
		}
	}

	for (int i = 0; i < 26; i++) {
		if (idr[i]) {
			cout << "Impossible" << nl;
			return;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << (char)('a' + ans[i]);
	}
	cout << nl;
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