class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int m = s.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
                dp[i][j] = s[i - 1] == s2[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        }
        return dp[m][n];
    }
};