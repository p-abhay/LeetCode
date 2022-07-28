class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        while((i < s.size()) || (j < t.size()) ) {
            mp[s[i++]] += 1;
            mp[t[j++]] -= 1;
        }
        for(auto i : mp) {
            cout<<i.second<<"\n";
            if(i.second)
                return false;
        }
        return true;
    }
};