class Solution {
public:
    int solve(int a, int b, vector<vector<int>>& dp) {

        // Reached starting cell
        if (a == 0 && b == 0)
            return 1;

        // Went outside the grid
        if (a < 0 || b < 0)
            return 0;

        // Already calculated
        if (dp[a][b] != -1)
            return dp[a][b];

        // Come from top OR come from left
        return dp[a][b] = solve(a - 1, b, dp) + solve(a, b - 1, dp);
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, dp);
    }
};