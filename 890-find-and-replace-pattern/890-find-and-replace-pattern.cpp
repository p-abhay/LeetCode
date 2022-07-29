class Solution {
public:
    string patternInNum(string &pattern) {
        string inNum = "";
        char num = '1';
        map<char,char> mp;
        for(int i = 0; i < pattern.size(); i++) {
            if(mp.find(pattern[i]) == mp.end())
                mp[pattern[i]] = num++;
            inNum += mp[pattern[i]];
        }
        return inNum;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        pattern = patternInNum(pattern);
        for(auto word : words) {
            string str = word;
            if(pattern == patternInNum(str))
                ans.push_back(word);
        }
        return ans;
    }
};