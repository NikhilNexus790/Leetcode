class Solution {
public:
    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {

        // If word1 is exhausted
        if (i < 0)
            return j + 1;

        // If word2 is exhausted
        if (j < 0)
            return i + 1;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters are same
        if (word1[i] == word2[j]) {
            return dp[i][j] =
                solve(i - 1, j - 1, word1, word2, dp);
        }

        // Characters are different
        int insert = solve(i, j - 1, word1, word2, dp);
        int remove = solve(i - 1, j, word1, word2, dp);
        int replace = solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] =
            1 + min({insert, remove, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, word1, word2, dp);
    }
};