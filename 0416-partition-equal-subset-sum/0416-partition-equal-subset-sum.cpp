class Solution {
public:
    bool subsetsum(vector<int>& nums, int n, int target,
                   vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (n == 0)
            return false;

        if (dp[n][target] != -1)
            return dp[n][target];

        if (nums[n - 1] > target) {
            return dp[n][target] = subsetsum(nums, n - 1, target, dp);
        }

        return dp[n][target] = subsetsum(nums, n - 1, target, dp) ||
                               subsetsum(nums, n - 1, target - nums[n - 1], dp);
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return subsetsum(nums, n, target, dp);
    }
};