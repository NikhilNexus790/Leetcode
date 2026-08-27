class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        // If index is negative, no element to pick
        if (i < 0)
            return 0;

        
        if (i == 0)
            return nums[0];

     
        if (dp[i] != -1)
            return dp[i];

        
        int pick = nums[i] + solve(nums, i - 2, dp);

        // Exclude current and move 1 back
        int notPick = solve(nums, i - 1, dp);

        // Store and return max of both choices
        return dp[i] = max(pick, notPick);
    }

    
    int rob(vector<int>& nums) {
        int n = nums.size();

        
        vector<int> dp(n + 1, -1);

       
        return solve(nums, n - 1, dp);
    }
};