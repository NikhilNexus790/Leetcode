class Solution {
public:

    int solve(int ind, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

        // Base case: no days left
        if (ind == prices.size())
            return 0;

        // Already calculated
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 0) {

            // Option 1: Don't buy
            int notBuy = solve(ind + 1, 0, prices, dp);

            // Option 2: Buy
            int Buy = -prices[ind] +
                      solve(ind + 1, 1, prices, dp);

            dp[ind][buy] = max(notBuy, Buy);
        }

        else {

            // Option 1: Don't sell
            int notSell = solve(ind + 1, 1, prices, dp);

            // Option 2: Sell
            int Sell = prices[ind] +
                       solve(ind + 1, 0, prices, dp);

            dp[ind][buy] = max(notSell, Sell);
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // n+1 rows and 2 columns
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Base case initialization
        dp[n][0] = 0;
        dp[n][1] = 0;

        return solve(0, 0, prices, dp);
    }
};