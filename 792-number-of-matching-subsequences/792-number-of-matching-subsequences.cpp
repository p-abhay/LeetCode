class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        map<char,vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        for(auto word : words) {
            bool check = true;
            for(int i = 0,prev = -1; i < word.size() && check; i++) {
                vector<int>& curr = mp[word[i]];
                auto it = upper_bound(curr.begin(), curr.end(), prev);
                if(it == curr.end())
                    check = false;
                else
                    prev = *it;
            }
            if(check)
                ans += 1;
        }
        return ans;
    }
};