#include <bits/stdc++.h>

using namespace std;

struct QuadTree {
	int n;
	vector<vector<int>> sum;

	QuadTree(int n) : n(n), sum(n << 2, vector<int>(n << 2, 0)) {}

	void update(int x, int y, int v, int nx = 1, int lx = 0, int rx = -1,
				int ny = 1, int ly = 0, int ry = -1) {
		if (rx == -1) rx = n - 1, ry = n - 1;
		if (lx > x || rx < x || ly > y || ry < y) return;
		if (lx == rx && ly == ry) {
			sum[nx][ny] += v;
			return;
		}
		int mx = lx + ((rx - lx) >> 1), my = ly + ((ry - ly) >> 1);
		update(x, y, v, nx << 1, lx, mx, ny << 1, ly, my);
		update(x, y, v, nx << 1, lx, mx, ny << 1 | 1, my + 1, ry);
		update(x, y, v, nx << 1 | 1, mx + 1, rx, ny << 1, ly, my);
		update(x, y, v, nx << 1 | 1, mx + 1, rx, ny << 1 | 1, my + 1, ry);
		sum[nx][ny] = sum[nx << 1][ny << 1] + sum[nx << 1][ny << 1 | 1] +
					  sum[nx << 1 | 1][ny << 1] + sum[nx << 1 | 1][ny << 1 | 1];
	}

	long long query(int qlx, int qrx, int qly, int qry, int nx = 1, int lx = 0,
					int rx = -1, int ny = 1, int ly = 0, int ry = -1) {
		if (rx == -1) rx = n - 1, ry = n - 1;
		if (lx > qrx || rx < qlx || ly > qry || ry < qly) return 0;
		if (qlx <= lx && rx <= qrx && qly <= ly && ry <= qry)
			return sum[nx][ny];
		int mx = lx + ((rx - lx) >> 1), my = ly + ((ry - ly) >> 1);
		return query(qlx, qrx, qly, qry, nx << 1, lx, mx, ny << 1, ly, my) +
			   query(qlx, qrx, qly, qry, nx << 1, lx, mx, ny << 1 | 1, my + 1,
					 ry) +
			   query(qlx, qrx, qly, qry, nx << 1 | 1, mx + 1, rx, ny << 1, ly,
					 my) +
			   query(qlx, qrx, qly, qry, nx << 1 | 1, mx + 1, rx, ny << 1 | 1,
					 my + 1, ry);
	}
};

int main() { return 1; }