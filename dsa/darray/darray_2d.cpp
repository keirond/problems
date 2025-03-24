#include <bits/stdc++.h>

using namespace std;

struct DiffArr {
	int n, m;
	vector<vector<long long>> diff, nums;

	DiffArr(vector<vector<long long>> &nums) {
		n = nums.size();
		m = n == 0 ? 0 : nums[0].size();

		diff.assign(n + 1, vector<long long>(m + 1, 0));
		this->nums.resize(n);
		for (int i = 0; i < n; ++i) {
			this->nums[i].assign(nums[i].begin(), nums[i].end());
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				diff[i][j] = nums[i][j];
				if (i > 0) diff[i][j] -= nums[i - 1][j];
				if (j > 0) diff[i][j] -= nums[i][j - 1];
				if (i > 0 && j > 0) diff[i][j] += nums[i - 1][j - 1];
			}
		}
	}

	void reconstruct() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				nums[i][j] = diff[i][j];
				if (i > 0) nums[i][j] += nums[i - 1][j];
				if (j > 0) nums[i][j] += nums[i][j - 1];
				if (i > 0 && j > 0) nums[i][j] -= nums[i - 1][j - 1];
			}
		}
	}

	void update(int lx, int rx, int ly, int ry, int val) {
		diff[lx][ly] += val;
		diff[lx][ry + 1] -= val;
		diff[rx + 1][ly] -= val;
		diff[rx + 1][ry + 1] += val;
	}

	long long query(int x, int y) {
		long long ans = 0;
		for (int i = 0; i <= x; ++i) {
			for (int j = 0; j <= y; ++j) {
				ans += diff[i][j];
			}
		}
		return ans;
	}

	long long query_after_reconstruct(int x, int y) { return nums[x][y]; }
};

int main() { return 1; }