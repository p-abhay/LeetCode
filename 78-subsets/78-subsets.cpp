class Solution {
public:
    vector<vector<int>> ans;
    void fun(int i,vector<int> out,vector<int> in)
    {
        if(i == in.size())
        {
            ans.push_back(out);
            return;
        }
        fun(i+1 , out , in);
        out.push_back(in[i]);
        fun(i+1 , out , in);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> out;
        fun(0 ,out, nums);
        return ans;
        
    }
};