class Solution {
public:
    bool check(string s) {
        int l = 0,r = s.size()-1;
        //cout<<s<<"in";
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1)
            return "";
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                cnt += 1;
                continue;
            }
            char ch = s[i];
            s[i] = 'a';
            
            if(!check(s)) {
                //cout<<s<<" ";
                return s;
            }
                
            s[i] = ch;
        }
        //if(cnt == n)
            s[n-1] = 'b';
        return s;
    }
};