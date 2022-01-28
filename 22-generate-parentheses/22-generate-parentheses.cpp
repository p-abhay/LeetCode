class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("",n,n,ans);
        return ans;
        
    }
private:
    void solve(string output, int open ,int close,vector<string>& ans)
    {
        //cout<<output<<" ";
        if(open == 0 and close == 0)
        {
            
            ans.push_back(output);
            return;
        }
        if((open != 0) and (open < close))
        {
            solve(output + "(",open-1,close,ans);
            solve(output + ")",open,close-1,ans);
        }
        else 
        {   if(open == 0)
                solve(output + ")",open,close-1,ans);
            if(open == close)
                solve(output + "(",open-1,close,ans);
        }
         
    }
};