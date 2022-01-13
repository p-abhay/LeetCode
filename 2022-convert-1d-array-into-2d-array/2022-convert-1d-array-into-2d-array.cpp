class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> ans;
        if(original.size()!=m*n)
            return ans;
        for(int i=0;i<m;i++)
        {
            ans.push_back(vector<int>());
            for(int j=i*n;j<(i+1)*n;j++)
                ans[i].push_back(original[j]);
        }
        
        return ans;
    }
};