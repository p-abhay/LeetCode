class Solution {
public:
    string reverseVowels(string s) {
        int m = 0;
        int n = s.size() - 1;
        string vowel = "aeiouAEIOU";
        while(m < n)
        {
            if((vowel.find(s[m]) != string :: npos) && (vowel.find(s[n]) != string :: npos))
            {
                swap(s[m], s[n]);
                m += 1;
                n -= 1;
            }
                
            if(vowel.find(s[m]) == string :: npos)
                m += 1;
            if(vowel.find(s[n]) == string :: npos)
                n -= 1;
        }
        return s;
    }
};