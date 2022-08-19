class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector<int> presum(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            presum[i] = sum;
        }
        if((presum[n-1] - presum[0]) == 0)
            return 0;
        
        for(int i = 0; i < n-1; i++) {
            //cout<<presum[i]<<" "<<(presum[n-1] - presum[i+1])<<"\n";
            if(presum[i] == (presum[n-1] - presum[i+1]))
                return (i+1);
        }
        if((presum[n-2]) == 0)
            return (n-1);
        return -1;
    }
};