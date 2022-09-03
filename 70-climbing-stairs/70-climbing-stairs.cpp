class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = solve(dp,n);
        return ans;
    }
    int solve(vector<int>& dp, int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = solve(dp,n-1) + solve(dp,n-2);
    }
};