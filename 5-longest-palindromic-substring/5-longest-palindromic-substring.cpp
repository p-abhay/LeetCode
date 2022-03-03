class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int start, end;
        for(int g = 0; g < size; g++) {
            for(int i = 0, j = g; j < size; i++,j++) {
                if(g == 0)
                {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }  
                else if(g == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] =true;
                        start = i;
                        end = j;
                    }
                }
                else if(s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] =true;
                    start = i;
                    end = j;
                }
            }
        }
        string ans = "";
        for(int i = start; i < end + 1; i++)
            ans += s[i];
        return ans;
    }
};