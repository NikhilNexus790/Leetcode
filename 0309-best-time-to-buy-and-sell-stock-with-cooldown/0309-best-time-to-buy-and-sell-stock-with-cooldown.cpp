class Solution {
public:

    int solve(int ind, int buy,
              vector<int>& prices,
              vector<vector<int>>& dp) {

        // No days left
        if (ind >= prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 0) {

            // Don't buy
            int notBuy = solve(ind + 1, 0, prices, dp);

            // Buy
            int Buy = -prices[ind]
                    + solve(ind + 1, 1, prices, dp);

            dp[ind][buy] = max(notBuy, Buy);
        }

        else {

            // Don't sell
            int notSell = solve(ind + 1, 1, prices, dp);

            // Sell -> cooldown -> jump to ind + 2
            int Sell = prices[ind]
                     + solve(ind + 2, 0, prices, dp);

            dp[ind][buy] = max(notSell, Sell);
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2, -1)
        );

        return solve(0, 0, prices, dp);
    }
};