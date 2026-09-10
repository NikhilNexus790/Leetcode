class Solution {
public:

    int solve(int ind, int buy, int cap,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        // Base case
        if (ind == prices.size() || cap == 0)
            return 0;

        // Already calculated
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy == 0) {

            // Option 1: Don't buy
            int notBuy = solve(ind + 1, 0, cap, prices, dp);

            // Option 2: Buy
            int Buy = -prices[ind] +
                      solve(ind + 1, 1, cap, prices, dp);

            dp[ind][buy][cap] = max(notBuy, Buy);
        }

        else {

            // Option 1: Don't sell
            int notSell = solve(ind + 1, 1, cap, prices, dp);

            // Option 2: Sell
            // One transaction is completed
            int Sell = prices[ind] +
                       solve(ind + 1, 0, cap - 1, prices, dp);

            dp[ind][buy][cap] = max(notSell, Sell);
        }

        return dp[ind][buy][cap];
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // dp[n+1][2][3]
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(
                2,
                vector<int>(3, -1)
            )
        );

        return solve(0, 0, 2, prices, dp);
    }
};