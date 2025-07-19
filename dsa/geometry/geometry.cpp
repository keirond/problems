#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Vector {
	double x, y;

	Vector operator*(double k) const { return {x * k, y * k}; }
	Vector operator/(double k) const { return {x / k, y / k}; }

	double norm() const { return hypot(x, y); }

	double dot(const Vector &other) const { return x * other.x + y * other.y; }

	double cross(const Vector &other) const {
		return x * other.y - y * other.x;
	}

	double angle(const Vector &other) const {
		double magA = norm();
		double magB = other.norm();
		double dotAB = dot(other);
		double cosTheta = dotAB / (magA * magB);
		cosTheta = max(-1.0, min(1.0, cosTheta));
		double angleTheta = acos(cosTheta);
		return angleTheta * 180 / M_PI;
	}

	Vector unit() const { return (*this) / norm(); }

	Vector rotate(double theta) const {
		double cosTheta = cos(theta);
		double sinTheta = sin(theta);
		return {x * cosTheta - y * sinTheta, x * sinTheta + y * cosTheta};
	}

	Vector normal() const { return {-y, x}; }
};

struct Point {
	double x, y;

	Vector operator-(const Point &other) const {
		return {x - other.x, y - other.y};
	}

	Point operator+(const Vector &other) const {
		return {x + other.x, y + other.y};
	}

	Point operator-(const Vector &other) const {
		return {x - other.x, y - other.y};
	}

	double dist(const Point &other) const { return (*this - other).norm(); }

	double cross(const Point &other) const { return x * other.y - y * other.x; }
};

bool isPointOnLine(const Point &p, const Point &a, const Point &b) {
	return abs((p - a).cross(b - a)) < 1e-9;
}

bool isPointOnSegment(const Point &p, const Point &a, const Point &b) {
	if (!isPointOnLine(p, a, b)) return false;
	return (p - a).dot(b - a) >= -1e-9;
}

double distPointToLine(const Point &p, const Point &a, const Point &b) {
	double cross = (p - a).cross(b - a);
	double mag = (b - a).norm();
	return abs(cross) / mag;
}

double distPointToSegment(const Point &p, const Point &a, const Point &b) {
	double magSquared = (b - a).dot(b - a);
	if (abs(magSquared) < 1e-9) return (p - a).norm();

	double t = (p - a).dot(b - a) / magSquared;
	if (t < 0.0) return (p - a).norm();
	if (t > 1.0) return (p - b).norm();

	Point proj = a + (b - a) * t;
	return (p - proj).norm();
}

optional<Point> lineLineIntersection(const Point &a1, const Point &a2,
									 const Point &b1, const Point &b2) {
	Vector da = a2 - a1;
	Vector db = b2 - b1;
	Vector dc = b1 - a1;  // notice here

	double s = da.cross(db);
	if (abs(s) < 1e-9) return nullopt;

	double t = dc.cross(db) / s;
	return a1 + da * t;
}

int orientation(const Point &a, const Point &b, const Point &c) {
	// 0: go straight
	// 1: turn left
	// -1: turn right
	double cross = (b - a).cross(c - b);
	if (abs(cross) < 1e-9) return 0;
	return (cross > 0) ? 1 : -1;
}

bool areSegmentsIntersect(const Point &a1, const Point &a2, const Point &b1,
						  const Point &b2) {
	int o1 = orientation(a1, a2, b1);
	int o2 = orientation(a1, a2, b2);
	int o3 = orientation(b1, b2, a1);
	int o4 = orientation(b1, b2, a2);

	if (o1 != o2 && o3 != o4) return true;

	if (o1 == 0 && isPointOnSegment(b1, a1, a2)) return true;
	if (o2 == 0 && isPointOnSegment(b2, a1, a2)) return true;
	if (o3 == 0 && isPointOnSegment(a1, b1, b2)) return true;
	if (o4 == 0 && isPointOnSegment(a2, b1, b2)) return true;

	return false;
}

bool areParallel(const Point &a1, const Point &a2, const Point &b1,
				 const Point &b2) {
	double cross = (a2 - a1).cross(b2 - b1);
	if (abs(cross) < 1e-9) return true;
	return false;
}

bool arePerpendicular(const Point &a1, const Point &a2, const Point &b1,
					  const Point &b2) {
	double dot = (a2 - a1).dot(b2 - b1);
	if (abs(dot) < 1e-9) return true;
	return false;
}

Point projectPointOnToLine(const Point &p, const Point &a, const Point &b) {
	double magSquared = (b - a).dot(b - a);
	double t = (p - a).dot(b - a) / magSquared;
	return a + (b - a) * t;
}

Point reflectPointOverLine(const Point &p, const Point &a, const Point &b) {
	Point q = projectPointOnToLine(p, a, b);
	return q + (q - p);
}

double area(const Point &a, const Point &b, const Point &c) {
	return abs((b - a).cross(c - a)) * 0.5;
}

double area(const vector<Point> &ps) {
	int n = ps.size();
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		Point a = ps[i];
		Point b = ps[(i + 1) % n];
		ans += a.cross(b);
	}
	return abs(ans) * 0.5;
}

bool isPointInsidePolygon(const Point &p, const vector<Point> &ps) {
	int n = ps.size();
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		Point a = ps[i];
		Point b = ps[(i + 1) % n];

		double cross = (b - a).cross(p - a);

		// if point-on-edge is included
		if (abs(cross) < 1e-9 && isPointOnSegment(p, a, b)) return true;

		if (a.y <= p.y) {
			if (b.y > p.y && cross > 0) cnt++;
		} else {
			if (b.y <= p.y && cross < 0) cnt--;
		}
	}
	return cnt != 0;
}

bool isConvexPolygon(const vector<Point> &ps) {
	int n = ps.size();
	if (n < 3) return false;

	int sign = 0;
	for (int i = 0; i < n; i++) {
		Point a = ps[i];
		Point b = ps[(i + 1) % n];
		Point c = ps[(i + 2) % n];

		Vector ab = b - a;
		Vector bc = c - b;

		double cross = ab.cross(bc);

		if (abs(cross) < 1e-9) continue;
		if (sign == 0) {
			sign = (cross > 0) ? 1 : -1;
		} else if ((cross > 0 && sign < 0) || (cross < 0 && sign > 0)) {
			return false;
		}
	}
	return true;
}

vector<Point> circleLineIntersection(const Point &c, double r, const Point &p,
									 const Vector &d) {
	double A = d.dot(d);
	double B = (p - c).dot(d) * 2.0;
	double C = (p - c).dot(p - c) - r * r;

	double delta = B * B - A * C * 4.0;

	vector<Point> ans;
	if (delta < -1e-9) return ans;

	delta = max(delta, 0.0);
	double sqrtDelta = sqrt(delta);

	double t1 = (-B - sqrtDelta) / (A * 2.0);
	double t2 = (-B + sqrtDelta) / (A * 2.0);

	ans.push_back(p + d * t1);
	if (sqrtDelta > 1e-9) ans.push_back(p + d * t2);
	return ans;
}

vector<Point> circleSegmentInteraction(const Point &c, double r, const Point &a,
									   const Point &b) {
	Vector d = b - a;

	double A = d.dot(d);
	double B = (a - c).dot(d) * 2.0;
	double C = (a - c).dot(a - c) - r * r;

	double delta = B * B - A * C * 4.0;

	vector<Point> ans;
	if (delta < -1e-9) return ans;

	delta = max(delta, 0.0);
	double sqrtDelta = sqrt(delta);

	double t1 = (-B - sqrtDelta) / (A * 2.0);
	double t2 = (-B + sqrtDelta) / (A * 2.0);

	if (t1 >= 0 && t1 <= 1) ans.push_back(a + d * t1);
	if (sqrtDelta > 1e-9 && t2 >= 0 && t2 <= 1) ans.push_back(a + d * t2);
	return ans;
}

vector<Point> circleCircleIntersection(const Point &c1, double r1,
									   const Point &c2, double r2) {
	Vector d = c2 - c1;
	double dist = d.norm();
	double dist2 = d.dot(d);

	if (dist > r1 + r2 + 1e-9) return {};
	if (dist < abs(r1 - r2) - 1e-9) return {};
	if (dist <= 1e-9 && abs(r1 - r2) <= 1e-9) return {};

	double a = (r1 * r1 - r2 * r2 + dist2) / (dist * 2.0);
	double h2 = r1 * r1 - a * a;

	if (h2 < -1e-9) return {};
	Point q = c1 + d * (a / dist);
	if (abs(h2) <= 1e-9) return {q};

	double h = sqrt(max(h2, 0.0));
	Vector perp = Vector({-d.y, d.x}) * (h / dist);
	return {q + perp, q - perp};
}

optional<pair<Point, Point>> tangentsFromPointToCircle(const Point &p,
													   const Point &c,
													   double r) {
	Vector d = p - c;
	double dist2 = d.dot(d);
	double r2 = r * r;

	if (dist2 < r2 - 1e-9) return nullopt;
	if (abs(dist2 - r2) < 1e-9) return {{p, p}};

	double dist = d.norm();

	Vector ud = d / dist;
	Vector uperp{-ud.y, ud.x};

	double e = r2 / dist;
	double h = sqrt(r2 - e * e);
	Point t1 = c + ud * e + uperp * h;
	Point t2 = c + ud * e - uperp * h;

	return {{t1, t2}};
}

optional<pair<Point, Point>> tangentsFromCircleToCircle(const Point &p,
													   const Point &c,
													   double r) {
	Vector d = p - c;
	double dist2 = d.dot(d);
	double r2 = r * r;

	if (dist2 < r2 - 1e-9) return nullopt;
	if (abs(dist2 - r2) < 1e-9) return {{p, p}};

	double dist = d.norm();

	Vector ud = d / dist;
	Vector uperp{-ud.y, ud.x};

	double e = r2 / dist;
	double h = sqrt(r2 - e * e);
	Point t1 = c + ud * e + uperp * h;
	Point t2 = c + ud * e - uperp * h;

	return {{t1, t2}};
}

// **************************************************************************

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