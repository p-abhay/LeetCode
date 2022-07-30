class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> count(26,0);
        vector<int> temp(26);
        for(auto s : words2) {
            temp = counter(s);
            for(int i = 0; i < 26; i++) {
                count[i] = max(count[i], temp[i]);
            }
        }
        // for(auto i : count)
        //     cout<<i<<":";
        int i;
        for(auto s : words1) {
            temp = counter(s);
            for(i = 0; i < 26; i++) {
                if(count[i] > temp[i])
                    break;
            }
            if(i == 26)
                ans.push_back(s);
        }
        return ans;
    }
    vector<int> counter(string& s) {
        vector<int> temp(26);
        for(auto ch : s) {
            temp[ch-'a']++;
        }
        return temp;
    }
};