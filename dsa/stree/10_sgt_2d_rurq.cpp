#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;

struct STree {
	int n, m;
	vvl tree;

	STree(vvi &nums) {
		n = nums.size();
		m = n == 0 ? 0 : nums[0].size();
		tree.assign(n << 2, vl(m << 2, 0));
		build_x(nums, 1, 0, n - 1);
	}

	void build_y(vvi &nums, int vx, int lx, int rx, int vy, int ly, int ry) {
		if (ly == ry) {
			if (lx == rx)
				tree[vx][vy] = nums[lx][ly];
			else
				tree[vx][vy] = tree[vx << 1][vy] + tree[vx << 1 | 1][vy];
			return;
		}
		int my = ly + ((ry - ly) >> 1);
		build_y(nums, vx, lx, rx, vy << 1, ly, my);
		build_y(nums, vx, lx, rx, vy << 1 | 1, my + 1, ry);
		tree[vx][vy] = tree[vx][vy << 1] + tree[vx][vy << 1 | 1];
	}

	void build_x(vvi &nums, int vx, int lx, int rx) {
		if (lx != rx) {
			int mx = lx + ((rx - lx) >> 1);
			build_x(nums, vx << 1, lx, mx);
			build_x(nums, vx << 1 | 1, mx + 1, rx);
		}
		build_y(nums, vx, lx, rx, 1, 0, m - 1);
	}

	void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
				  int val) {
		if (ly == ry) {
			if (lx == rx) {
				tree[vx][vy] = val;
			} else {
				tree[vx][vy] = tree[vx << 1][vy] + tree[vx << 1 | 1][vy];
			}
			return;
		}
		int my = ly + ((ry - ly) >> 1);
		if (y <= my)
			update_y(vx, lx, rx, vy << 1, ly, my, x, y, val);
		else
			update_y(vx, lx, rx, vy << 1 | 1, my + 1, ry, x, y, val);
		tree[vx][vy] = tree[vx][vy << 1] + tree[vx][vy << 1 | 1];
	}

	void update_x(int vx, int lx, int rx, int x, int y, int val) {
		if (lx != rx) {
			int mx = lx + ((rx - lx) >> 1);
			if (x <= mx)
				update_x(vx << 1, lx, mx, x, y, val);
			else
				update_x(vx << 1 | 1, mx + 1, rx, x, y, val);
		}
		update_y(vx, lx, rx, 1, 0, m - 1, x, y, val);
	}

	void update(int x, int y, int val) { update_x(1, 0, n - 1, x, y, val); }

	long long query_y(int vx, int vy, int ly, int ry, int qly, int qry) {
		if (qry < ly || qly > ry) return 0;
		if (qly <= ly && ry <= qry) return tree[vx][vy];
		int my = ly + ((ry - ly) >> 1);
		return query_y(vx, vy << 1, ly, my, qly, qry) +
			   query_y(vx, vy << 1 | 1, my + 1, ry, qly, qry);
	}

	long long query_x(int vx, int lx, int rx, int qlx, int qrx, int qly,
					  int qry) {
		if (qrx < lx || qlx > rx) return 0;
		if (qlx <= lx && rx <= qrx) return query_y(vx, 1, 0, m - 1, qly, qry);
		int mx = lx + ((rx - lx) >> 1);
		return query_x(vx << 1, lx, mx, qlx, qrx, qly, qry) +
			   query_x(vx << 1 | 1, mx + 1, rx, qlx, qrx, qly, qry);
	}

	long long query(int lx, int rx, int ly, int ry) {
		return query_x(1, 0, n - 1, lx, rx, ly, ry);
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> nums(N, vector<int>(M));
	for (auto &d : nums)
		for (auto &e : d) cin >> e;

	STree st(nums);

	int Q;
	cin >> Q;
	while (Q--) {
		int op, lx, ly, rx, ry, val;
		cin >> op;
		if (op == 1) {
			cin >> lx >> ly >> val;
			st.update(lx, ly, val);
		} else if (op == 2) {
			cin >> lx >> ly >> rx >> ry;
			cout << st.query(lx, rx, ly, ry) << '\n';
		}
	}
	return 0;
}