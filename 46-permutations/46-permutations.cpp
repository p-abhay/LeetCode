class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        backtrack(0, size - 1, nums, ans);
        return ans;
    }
private:
    void backtrack(int start, int end, vector<int> nums, vector<vector<int>>& ans) {
        if(start == end)
            ans.push_back(nums);
        else
        {
            for(int i = start; i <= end; i++) {
                swap(nums[start], nums[i]);
                backtrack(start + 1, end, nums, ans);
                swap(nums[start], nums[i]);
            }
            
        }
        
        
    }
};