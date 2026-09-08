#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(n - 1, amount, coins, dp);

        if (ans == 1e9)
            return -1;

        return ans;
    }

private:
    int helper(int i, int amount, vector<int>& coins,
               vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (i < 0)
            return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i] <= amount) {
            dp[i][amount] = min(
                1 + helper(i, amount - coins[i], coins, dp),
                helper(i - 1, amount, coins, dp)
            );
        }
        else {
            dp[i][amount] = helper(i - 1, amount, coins, dp);
        }

        return dp[i][amount];
    }
};