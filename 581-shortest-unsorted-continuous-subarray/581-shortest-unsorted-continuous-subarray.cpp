class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int check = 0;
        int minr = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) {
                check = 1;
            }
            if(check) {
                minr = min(minr, nums[i]);
            }
        }
        for(start = 0; start < n - 1; start++) {
            if(minr < nums[start])
                break;
        }
        int end = -1;
        int maxl = INT_MIN;
        check = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > nums[i+1]) {
                check = 1;
            }
            if(check) {
                maxl = max(maxl, nums[i]);
            }
        }
        for(end = n - 1; end >= 0; end--) {
            if(maxl > nums[end])
                break;
        }
        if(end - start + 1 < 0)
            return 0;
        return end - start + 1;
    }
};