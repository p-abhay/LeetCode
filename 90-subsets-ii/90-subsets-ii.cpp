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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> out;
        fun(0,out,nums);
        set<vector<int>> res(ans.begin(),ans.end());
        /*for(auto i = ans.begin(); i!=ans.end();i++)
            res.insert(*i);*/
        ans.clear();
        for(auto itr=res.begin();itr!=res.end();itr++)
            ans.push_back(*itr);
        return ans;
        
    }
};