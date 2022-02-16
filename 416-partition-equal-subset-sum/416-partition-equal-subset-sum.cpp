class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto i : nums)
            sum += i;
        
        if(sum % 2 == 0)
            return subsetSum(nums, n, sum/2);
        else
            return false;
        
    }
private:
    bool subsetSum(vector<int>& nums, int n, int sum) {
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, false));
        
        for(int i = 0; i < n + 1;i++)
        {
            dp[i][0] = true;
        }
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < sum + 1; j++)
            {
                if(nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }
};