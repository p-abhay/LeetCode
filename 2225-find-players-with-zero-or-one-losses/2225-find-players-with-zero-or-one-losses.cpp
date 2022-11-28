class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s1;
        map<int,int> mp;
        for(auto i : matches) {
            s1.insert(i[0]);
            mp[i[1]] += 1;
        }
        vector<vector<int>> ans;
        vector<int> v1,v2;
        for(auto i : s1) {
            if(mp.find(i) == mp.end()) {
                v1.push_back(i);
            }
        }
        for(auto i : mp) {
            if(i.second == 1)
                v2.push_back(i.first);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};