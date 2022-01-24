class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int size=nums.size();
        int low=0;
        int high=size-1;
        int mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        
        /*if (target>0)
            return mid+1;
        else
            return mid;*/
        return high+1;
    }
};