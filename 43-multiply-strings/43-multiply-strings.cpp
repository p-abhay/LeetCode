class Solution {
public:
    string multiply(string num1, string num2) {
        
        int s1=num1.size();
        int s2=num2.size();
        //cout<<s1<<" "<<s2<<endl;
        
        if(num1=="0" || num2=="0")
            return "0";
        vector<int> res(s1+s2,0);
        
        //cout<<res[0]<<res[1];
        for(int i=s1-1;i>=0;i--)
        {
            for(int j=s2-1;j>=0;j--)
            {
                res[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]=res[i+j+1]%10;
            }
        }
        //cout<<res[0]<<" "<<res[1];
        string ans="";
        int i=0;
        while(res[i]==0)i++;
        for(;i<s1+s2;i++)
            ans+=to_string(res[i]);
        
        //cout<<ans[0]<<" "<<ans[1];
        //cout<<ans;
        return ans;
    }
};