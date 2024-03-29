class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size();
        int len2 = text2.size();
        
        vector<vector<int>> dp(len2 + 1, vector<int> (len1 + 1, 0));

        
        for(int i = 1; i < len2 + 1; i++)
        {
            for(int j = 1; j < len1 + 1; j++)
            {
                //cout<<text1[i - 1]<<" "<<text2[j - 1]<<endl;
                if(text2[i - 1] == text1[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[len2][len1];
    }
};