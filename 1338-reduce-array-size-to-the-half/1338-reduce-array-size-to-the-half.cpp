class Solution {
public:
    // bool comp(pair<int,int> a, pair<int,int> b) {
    //     return a.second > b.second;
    // }
    int minSetSize(vector<int>& arr) {
        vector<pair<int,int>> v;
        map<int,int> mp;
        for(auto i : arr)
            mp[i] += 1;
        for(auto i : mp) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b) {
            return a.second > b.second;
        });
        int ans = 0;
        int count = 0;
        for(auto i : v) {
            count += i.second;
            ans += 1;
            if(count >= arr.size()/2)
                break;
        }
        return ans;
    }
};