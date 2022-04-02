class Solution {
public:
    bool validPalindrome(string s) {
       int m = 0;
       int n = s.size() - 1;
       while(m < n)
       {
           if(s[m] != s[n])
               return palindrome(s, m, n-1) || palindrome(s, m+1, n);
           m += 1;
           n -= 1;
       }
        return true;
    }
private:
    bool palindrome(string s, int m, int n) {
        while(m < n)
        {
            if(s[m] != s[n])
                return false;
            m += 1;
            n -= 1;
        }
        return true;
    }
};