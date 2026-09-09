class Solution {
public:
    int lcs(string &s, string &rev, int i, int j, vector<vector<int>> &dp) {

        // base case
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == rev[j])
            dp[i][j] = 1 + lcs(s, rev, i - 1, j - 1, dp);

        else
            dp[i][j] =
                max(lcs(s, rev, i - 1, j, dp), lcs(s, rev, i, j - 1, dp));

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        int n = s.length();
        int m = s.length();
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcs(s, rev, n - 1, m - 1, dp);
    }
};