class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        for(auto i : nums1)
            mp1[i]++;
        unordered_map<int, int> mp2;
        for(auto i : nums2)
            mp2[i]++;
        
        vector<vector<int>> ans;
        set<int> temp;
        for(auto i : nums1)
            if(mp2.find(i) == mp2.end())
                temp.insert(i);
        vector<int> temp_ans;
        for(auto i : temp)
            temp_ans.push_back(i);
        ans.push_back(temp_ans);
        temp.clear();
        for(auto i : nums2)
            if(mp1.find(i) == mp1.end())
                temp.insert(i);
        temp_ans.clear();
        for(auto i : temp)
            temp_ans.push_back(i);
        ans.push_back(temp_ans);
        return ans;
    }
};