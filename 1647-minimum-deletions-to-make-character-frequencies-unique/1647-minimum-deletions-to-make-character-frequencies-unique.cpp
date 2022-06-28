class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());    
        int count = 0;
        int maxFreq = s.size();
        
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            if (freq[i] > maxFreq) {
                count += freq[i] - maxFreq;
                freq[i] = maxFreq;
            }
            maxFreq = max(0, freq[i] - 1);
        }
        return count;
    }
};