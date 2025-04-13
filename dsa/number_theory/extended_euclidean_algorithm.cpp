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

// gcd(a, b) = gcd(b, a%b) till b = 0
// ax + by = gcd(a, b) = gcd(b, a%b) = ax1 + a%b*y1 = bx1 + (a - a/b*b)*y1
// ax + by = ay1 + b(x1 - qy1) with q = a/b
// x = y1 && y = x1 - q*y1

pair<int, int> regcd(int a, int b) {
	if (b == 0) return {1, 0};
	auto [x1, y1] = regcd(b, a % b);
	int x = y1, y = x1 - a / b * y1;
	return {x, y};
}

pair<int, int> egcd(int a, int b) {
	// ax + by = a0
	// ax' + by' = b0

	// a1 = b0, b1 = a0 - q*b0
	// ax' + by' = b0 = a1
	// a(x-qx') + b(y-qy') = a0 - q*b0 = b1
	// -->
	// ax + by = ak
	// ax + by = bk = 0
	int x = 1, y = 0;
	int x1 = 0, y1 = 1;
	while (b) {
		int q = a / b;
		a %= b;
		swap(a, b);
		x -= q * x1;
		swap(x, x1);
		y -= q * y1;
		swap(y, y1);
	}
	return {x, y};
}

void solve(int test_case [[maybe_unused]]) {
	auto [x, y] = regcd(10, 25);
	cout << x << ' ' << y << nl;

	tie(x, y) = egcd(10, 25);
	cout << x << ' ' << y << nl;
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