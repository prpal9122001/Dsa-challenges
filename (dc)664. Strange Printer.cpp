//https://leetcode.com/problems/strange-printer/description/
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        int dp[105][105];
        memset(dp, 0, sizeof(dp));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = 1 + dp[i+1][j]; // Case 1
                for (int k = i+1; k <= j; k++) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]); // Case 2
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
