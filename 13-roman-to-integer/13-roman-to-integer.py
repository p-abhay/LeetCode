class Solution:
    def romanToInt(self, s: str) -> int:
        mp={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        ans=0
        
        for i in range(0,len(s)-1):
            if s[i] == 'I':
                if s[i+1] == 'V' or s[i+1] == 'X':
                    ans+=-1
                else:
                    ans+=1
            elif s[i] == 'X':
                if s[i+1] == 'L' or s[i+1] == 'C':
                    ans+=-10
                else:
                    ans+=10
            elif s[i] == 'C':
                if s[i+1] == 'D' or s[i+1] == 'M':
                    ans+=-100
                else:
                    ans+=100
            else:
                ans+=mp[s[i]]
        ans+=mp[s[len(s)-1]]
        return ans
        