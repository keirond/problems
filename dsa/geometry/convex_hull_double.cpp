#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Point {
	double x, y;
	bool operator<(const Point &p) const {
		return abs(x - p.x) > 1e-9 ? x < p.x : y < p.y;
	}
};

double cross(const Point &a, const Point &b, const Point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convex_hull(const vector<Point> &ps) {
	int n = ps.size();
	if (n <= 1) return ps;

	sort(ps.begin(), ps.end());
	vector<Point> hull(2 * n);

	int k = 0;
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(hull[k - 2], hull[k - 1], ps[i]) < -1e-9) k--;
		hull[k++] = ps[i];
	}

	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && cross(hull[k - 2], hull[k - 1], ps[i]) < -1e-9) k--;
		hull[k++] = ps[i];
	}

	hull.resize(k - 1);
	return hull;
}

void solve(int test_case [[maybe_unused]]) {}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve(1);
	cout << flush;
	return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************