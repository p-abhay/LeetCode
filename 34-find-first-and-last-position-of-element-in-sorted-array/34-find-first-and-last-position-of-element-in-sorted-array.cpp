class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, -1};
        if(nums.size() == 0)
            return range;
        range[0] = binarySearch(nums, target);
        range[1] = binarySearch2(nums, target);
        // int low = 0;
        // int high = nums.size() - 1;
        // int freq = 0
        // while(low <= high)
        // {
        //     int mid = low + (high - low) / 2;
        //     if(target == nums[mid]) {
        //         high = mid - 1;
        //         low = mid + 1;
        //     }
        //     else if(nums[mid] < target)
        //         low = mid + 1;
        //     else
        //         high = mid - 1;       
        // }
        return range;
    }
private:
    int binarySearch(vector<int> nums, int target) {
        int low = 0,high = nums.size() - 1;
        int fi = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) {
                high = mid - 1;
                fi = mid;
            }
            else if(target > nums[mid])
                 low = mid + 1;
            else
                high = mid - 1;     
        }
        return fi;
    }
    int binarySearch2(vector<int> nums, int target) {
        int low = 0,high = nums.size() - 1;
        int ui = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) {
                low = mid + 1;
                ui = mid;
            }
            else if(target > nums[mid])
                 low = mid + 1;
            else
                high = mid - 1;    
        }
        return ui;
    }
};