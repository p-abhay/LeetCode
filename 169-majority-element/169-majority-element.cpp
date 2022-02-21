class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> freq;
        for(auto i : nums)
            freq[i]++;
        int ans = 0,count = -1;
        for(auto i : freq)
        {
            if(i.second > count)
            {
                ans = i.first;
                count = i.second;                
            }

        }
        
        return ans;
        
    }
};