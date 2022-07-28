class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1,mp2;
        for(auto i : s)
            mp1[i] += 1;
        for(auto i : t)
            mp2[i] += 1;
        auto itr1 = mp1.begin(), itr2 = mp2.begin();
        for(;itr1 != mp1.end() && itr2 != mp2.end();itr1++,itr2++) {
            if(itr1->first == itr2->first && itr2->second == itr1->second)
                continue;
            return false;
        }
        if(itr1 != mp1.end() || itr2 != mp2.end())
            return false;
        return true;
    }
};