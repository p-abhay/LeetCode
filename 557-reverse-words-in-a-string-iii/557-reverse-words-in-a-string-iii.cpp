class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int l = 0,r = s.size();
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ')
                continue;
            else {
                r = i;
                string word = s.substr(l,r-l);
                reverse(word.begin(),word.end());
                ans += word;
                ans += ' ';
                l = i+1;
            }
        }
        string word = s.substr(l,r-l);
        reverse(word.begin(),word.end());
        ans += word;
        return ans;
    }
};