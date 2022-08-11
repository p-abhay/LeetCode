class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr_ans;
        combiSum(0, candidates, target, curr_ans);
        return ans;
    }
    void combiSum(int i, vector<int>& candidates, int target, vector<int>& curr_ans) {
        if(target < 0 || i == candidates.size())
            return;
        if(target == 0) {
            ans.push_back(curr_ans);
            return;
        }
        
        curr_ans.push_back(candidates[i]);
        combiSum(i, candidates, target - candidates[i], curr_ans);
        curr_ans.pop_back();
        combiSum(i+1, candidates, target, curr_ans);
    }
};