class Solution {
public:

    int TargetSum(vector<int>& nums, int ind, int target,
                  vector<vector<int>>& dp) {

        // Base case
        if (ind == 0) {

            // nums[0] = 0 and target = 0
            // Two possibilities: +0 and -0
            if (target == 0 && nums[0] == 0)
                return 2;

            // Either pick nums[0] or don't pick it
            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        // Already calculated
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Don't pick nums[ind]
        int notTake = TargetSum(nums, ind - 1, target, dp);

        int take = 0;

        // Pick nums[ind] only if it doesn't exceed target
        if (nums[ind] <= target) {
            take = TargetSum(nums, ind - 1,
                             target - nums[ind], dp);
        }

        return dp[ind][target] = take + notTake;
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases
        if (totalSum + target < 0)
            return 0;

        if ((totalSum + target) % 2 != 0)
            return 0;

        // Convert Target Sum into Subset Sum
        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(subsetSum + 1, -1)
        );

        return TargetSum(nums, n - 1, subsetSum, dp);
    }
};