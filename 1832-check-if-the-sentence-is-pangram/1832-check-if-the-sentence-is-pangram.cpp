class Solution {
public:
    bool checkIfPangram(string sentence) {
        int alpha[26] = {0};
        for(auto ch : sentence) {
            if(alpha[ch-'a'] == 0) {
                alpha[ch-'a'] = 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < 26; i++)
            sum += alpha[i];
        if(sum == 26)
            return true;
        return false;
    }
};