#include <bits/stdc++.h>

using namespace std;

struct SqrtD {
	int n, blk_size;
	vector<long long> nums, blk;

	SqrtD(vector<int> &nums) {
		n = nums.size();
		this->nums = nums;
		blk_size = sqrt(n) + 1;
		blk.assign(blk_size, 0);

		for (int i = 0; i < n; ++i) {
			blk[i / blk_size] += nums[i];
		}
	}

	void update(int i, int val) {
		int blk_ind = i / blk_size;
		blk[blk_ind] += val - nums[i];
		nums[i] = val;
	}

	int query(int l, int r) {
		int ans = 0;
		int left_blk = l / blk_size, right_blk = r / blk_size;

		if (left_blk == right_blk) {
			for (int i = l; i <= r; ++i) ans += nums[i];
		} else {
			for (int i = l, end = (left_blk + 1) * blk_size - 1; i <= end; ++i)
				ans += nums[i];
			for (int i = left_blk + 1; i < right_blk; ++i) ans += blk[i];
			for (int i = right_blk * blk_size; i <= r; ++i) ans += nums[i];
		}
		return ans;
	}
};

int main() { return 1; }