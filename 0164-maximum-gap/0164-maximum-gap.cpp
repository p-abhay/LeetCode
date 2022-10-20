class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++) {
            int diff = abs(nums[i] - nums[i+1]);
            ans = max(ans,diff);
        }
        return ans;
    }
};