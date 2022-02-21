class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> num1;
        map<int,int> num2;
        for(auto i : nums1)
            num1[i]++;
        for(auto i : nums2)
            num2[i]++;
        vector<int> ans;
        //if(num1.size() < num2.size())
        /*{*/
            for(auto itr = num1.begin(); itr != num1.end(); itr++)
            {
                if(num2.find(itr->first) != num2.end())
                {
                    int freq = min(itr->second,num2.find(itr->first)->second);
                        while(freq--)
                            ans.push_back(itr->first);
                        
                }
            }
        /*}*/
        return ans;
        
    }
};