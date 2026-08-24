class Solution {
public:

    int TargetSum(vector<int>& nums, int sum,
                  vector<vector<int>>& dp, int n) {

        if (n == 0) {
            if (sum == 0)
                return 1;
            return 0;
        }

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] > sum) {
            return dp[n][sum] =
                TargetSum(nums, sum, dp, n - 1);
        }

        int notTake = TargetSum(nums, sum, dp, n - 1);

        int take = TargetSum(nums, sum - nums[n - 1], dp, n - 1);

        return dp[n][sum] = notTake + take;
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int TotalSum = accumulate(nums.begin(), nums.end(), 0);

        if (target + TotalSum < 0 ||
            (target + TotalSum) % 2 != 0)
            return 0;

        int sum1 = (target + TotalSum) / 2;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(sum1 + 1, -1)
        );

        return TargetSum(nums, sum1, dp, n);
    }
};