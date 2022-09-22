class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int k = index(0,size-1,nums);
        
        // for(int i = 0; i < size - 1; i++) {
        //     if(nums[i + 1] < nums[i]) {
        //         k = i;
        //         break;
        //     }
        // }
        cout<<k;
        if(k == 0)
            return binarySearch(0,size-1,nums,target);
        else if(target >= nums[0] && target <= nums[k-1])
            return binarySearch(0, k-1, nums, target);
        
        return binarySearch(k, size - 1, nums, target);
    }
private:
    int index(int l,int r,vector<int> nums) {
        if((nums[l] < nums[r]) || nums.size() == 1)
            return 0;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            if(nums[mid] > nums[mid+1]) {
                return (mid+1);
            }
            else if(nums[l] <= nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return -1;
    }
    int binarySearch(int low, int high, vector<int> nums, int target) {
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};