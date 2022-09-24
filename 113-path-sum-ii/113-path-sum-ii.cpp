/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root,targetSum,path,paths);
        return paths;
    }
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths) {
        //cout<<targetSum<<"\n";
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr && (targetSum-root->val) == 0) {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
            return;
        } 
        path.push_back(root->val);
        int sum = targetSum - root->val;
        dfs(root->left,sum,path,paths);
        dfs(root->right,sum,path,paths);
        path.pop_back();
    }
};