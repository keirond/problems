#include <bits/stdc++.h>

using namespace std;

struct DiffArr {
	int n;
	vector<long long> diff, nums;

	DiffArr(vector<int> &nums) {
		n = nums.size();
		diff.assign(n + 1, 0);
		this->nums.assign(nums.begin(), nums.end());

		diff[0] = nums[0];
		for (int i = 1; i < n; ++i) {
			diff[i] = nums[i] - nums[i - 1];
		}
	}

	void reconstruct() {
		nums[0] = diff[0];
		for (int i = 1; i < n; ++i) {
			nums[i] = nums[i - 1] + diff[i];
		}
	}

	void update(int l, int r, int val) {
		diff[l] += val;
		diff[r + 1] -= val;
	}

	long long query(int i) {
		long long ans = 0;
		for (int j = 0; j <= i; ++j) {
			ans += diff[j];
		}
		return ans;
	}

	long long query_after_reconstruct(int i) { return nums[i]; }
};

int main() { return 0; }