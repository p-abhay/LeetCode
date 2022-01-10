class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size= nums.size();
        map<int,int> n1;
        vector<int> ans;
        for(int i=0;i<size;i++)
        {
            if(n1.find(target-nums[i])==n1.end())
            {
                n1[nums[i]]=i;
            }
            else
            {
                ans.push_back(i);
                ans.push_back(n1[target-nums[i]]);
            }
        }
        return ans;
    }
};