class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr_ans;
        sort(candidates.begin(), candidates.end());
        combi2(0, candidates, target, curr_ans, ans);
        return ans;
    }
    void combi2(int i, vector<int>& candidates, int target, vector<int>& curr_ans,vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(curr_ans);
            return;
        }
        
        for(int j = i; j < candidates.size(); j++) {
            if(j > i && candidates[j] == candidates[j-1])
                continue;
            if(candidates[j] > target)
                break;
            curr_ans.push_back(candidates[j]);
            combi2(j+1, candidates, target - candidates[j], curr_ans, ans);
            curr_ans.pop_back();
        }    
    }
};