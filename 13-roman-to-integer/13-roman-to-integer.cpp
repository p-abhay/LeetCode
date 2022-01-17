class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='C') 
            {
                if(s[i+1]=='D' || s[i+1]=='M') 
                    ans+=-100;
                else
                    ans+=100;
            }
            else if(s[i]=='X') 
            {
                if(s[i+1]=='L' || s[i+1]=='C')
                    ans+=-10;
                else 
                    ans+=10;
            }
            else if(s[i]=='I') 
            {
                if(s[i+1]=='X' || s[i+1]=='V') 
                    ans+=-1;
                else 
                    ans+=1;
            }
            else 
                ans+=mp[s[i]];
        }
        ans+=mp[s[s.size()-1]];
        return ans;
    }
};