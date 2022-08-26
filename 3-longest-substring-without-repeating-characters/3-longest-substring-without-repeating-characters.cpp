class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int ans = INT_MIN;
        int curr_ans = 0;
        map<char,int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
                curr_ans += 1;
                //cout<<"check";
            }
            else{
                ans = max(curr_ans,ans);
                curr_ans = 0;
                int idx = mp[s[i]];
                mp.erase(mp.begin(),mp.end());
                i = idx;
            }
            
        }
        ans = max(curr_ans,ans);
        return ans;
    }
};