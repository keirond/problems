#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
};

bool isPointOnLine(const Point &p, const Point &a, const Point &b) {
	return abs((p - a).cross(b - a)) < 1e-9;
}

bool isPointOnSegment(const Point &p, const Point &a, const Point &b) {
	if (!isPointOnLine(p, a, b)) return false;
	return (p - a).dot(b - a) >= -1e-9;
}

double distPointLine(const Point &p, const Point &a, const Point &b) {
	double cross = (p - a).cross(b - a);
	double mag = (b - a).norm();
	return abs(cross) / mag;
}

double distPointSegment(const Point &p, const Point &a, const Point &b) {
	double magSquared = (b - a).dot(b - a);
	if (abs(magSquared) < 1e-9) return (p - a).norm();

	double t = (p - a).dot(b - a) / magSquared;
	if (t < 0.0) return (p - a).norm();
	if (t > 1.0) return (p - b).norm();

	return distPointLine(p, a, b);
}

optional<Point> lineLineIntersection(const Point &a1, const Point &a2,
									 const Point &b1, const Point &b2) {
	Vector da = a2 - a1;
	Vector db = b2 - b1;
	Vector dc = a1 - b1;

	double s = da.cross(db);
	if (abs(s) < 1e-9) return nullopt;

	double t = dc.cross(db) / s;
	return a1 - da * t;
}

bool areSegmentsIntersect(const Point &a1, const Point &a2, const Point &b1,
						  const Point &b2) {}

int orientation(const Point &a, const Point &b, const Point &c) {
	// 0: go straight
	// 1: turn left
	// -1: turn right
	double cross = (b - a).cross(c - b);
	if (abs(cross) < 1e-9) return 0;
	return (cross > 0) ? 1 : -1;
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