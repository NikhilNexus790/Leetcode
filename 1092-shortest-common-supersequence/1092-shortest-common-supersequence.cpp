class Solution {
public:

    int lcs(int i, int j, string& str1, string& str2,
            vector<vector<int>>& dp) {

        // Base case
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (str1[i - 1] == str2[j - 1]) {
            return dp[i][j] =
                1 + lcs(i - 1, j - 1, str1, str2, dp);
        }

        return dp[i][j] = max(
            lcs(i - 1, j, str1, str2, dp),
            lcs(i, j - 1, str1, str2, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // n+1 x m+1 because we are using 1-based DP
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int lcslength = lcs(n, m, str1, str2, dp);

        string ans = "";

        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            // Characters are same
            if (str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];

                i--;
                j--;
            }

            // Move toward greater LCS value
            else if (dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];

                i--;
            }

            else {

                ans += str2[j - 1];

                j--;
            }
        }

        // Remaining characters of str1
        while (i > 0) {

            ans += str1[i - 1];

            i--;
        }

        // Remaining characters of str2
        while (j > 0) {

            ans += str2[j - 1];

            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};