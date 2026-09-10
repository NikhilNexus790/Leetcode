class Solution {
public:

    int solve(int ind, int buy,
              vector<int>& prices,
              int fee,
              vector<vector<int>>& dp) {

        // No days left
        if (ind == prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 0) {

            // Don't buy
            int notBuy = solve(ind + 1, 0, prices, fee, dp);

            // Buy
            int Buy = -prices[ind]
                    + solve(ind + 1, 1, prices, fee, dp);

            dp[ind][buy] = max(notBuy, Buy);
        }

        else {

            // Don't sell
            int notSell = solve(ind + 1, 1, prices, fee, dp);

            // Sell and pay fee
            int Sell = prices[ind] - fee
                     + solve(ind + 1, 0, prices, fee, dp);

            dp[ind][buy] = max(notSell, Sell);
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2, -1)
        );

        return solve(0, 0, prices, fee, dp);
    }
};