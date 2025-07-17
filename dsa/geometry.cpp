#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Vector {
	double x, y;

	Vector operator/(double k) const { return {x / k, y / k}; }

	double norm() const { return hypot(x, y); }

	double dot(Vector other) const { return x * other.x + y * other.y; }

	double cross(Vector other) const { return x * other.y - y * other.x; }

	double angle(Vector other) const {
		double normA = norm();
		double normB = other.norm();
		double dotAB = dot(other);
		double cosTheta = dotAB / (normA * normB);
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

	Vector operator-(Point other) const { return {x - other.x, y - other.y}; }

	double dist(Point other) const { return (*this - other).norm(); }
};

bool isPointOnLine(const Point &p, const Point &a, const Point &b) {
	return abs((p - a).cross(b - a)) < 1e-9;
}

bool isPointOnSegment(const Point &p, const Point &a, const Point &b) {
	if (!isPointOnLine(p, a, b)) return false;
	return (a - p).dot(a - b) >= -1e-9;
}

double distPointLine(const Point &p, const Point &a, const Point &b) {}

double distPointSegment(const Point &p, const Point &a, const Point &b) {}

optional<Point> lineLineIntersection(const Point &a1, const Point &a2,
									 const Point &b1, const Point &b2) {}

bool areSegmentsIntersect(const Point &a1, const Point &a2, const Point &b1,
						  const Point &b2) {}

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