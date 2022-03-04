class Solution {
public:
    int rob(vector<int>& nums) {
        
        int include = nums[0];
        int exclude = 0;
        for(int i = 1; i < nums.size(); i++) {
            int n_include = exclude + nums[i];
            int n_exclude = max(exclude, include);
            include = n_include;
            exclude = n_exclude;
        }
        return max(include, exclude);
    }
};