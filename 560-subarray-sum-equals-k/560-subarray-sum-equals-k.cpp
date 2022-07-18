class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, long> mp;
        long long sum = 0;
        int ans = 0;
        mp[sum] = 1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum-k];
            mp[sum] += 1;
        }
        
        return ans;
    }
};