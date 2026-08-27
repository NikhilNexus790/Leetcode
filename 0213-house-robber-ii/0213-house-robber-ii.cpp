class Solution {
public:
    int solve(vector<int>& arr, int i, vector<int>& dp) {
        // If index is negative, no element to pick
        if (i < 0)
            return 0;

        if (i == 0)
            return arr[0];

        if (dp[i] != -1)
            return dp[i];

        int pick = arr[i] + solve(arr, i - 2, dp);

        // Exclude current and move 1 back
        int notPick = solve(arr, i - 1, dp);

        // Store and return max of both choices
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        // Create two arrays:
        // arr1 excludes the first house
        // arr2 excludes the last house
        vector<int> arr1, arr2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                arr1.push_back(nums[i]);
            if (i != n - 1)
                arr2.push_back(nums[i]);
        }
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        long long int ans1 = solve(arr1, n - 2, dp1);
        long long int ans2 = solve(arr2, n - 2, dp2);
        return max(ans1, ans2);
    }
};