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
    int goodNodes(TreeNode* root) {
        int max = root->val;
        int ans = 0;
        solve(root,max,ans);
        return ans;
    }
    void solve(TreeNode* root, int& max, int& ans) {
        set<TreeNode*> visited;
        dfs(root,max,ans,visited);
    }
    void dfs(TreeNode* root, int max, int& ans, set<TreeNode*>& visited) {
        if(root == nullptr)
            return;
        if(root->val >= max) {
            max = root->val;
            ans += 1;
        }
        visited.insert(root);
        if(visited.find(root->left) == visited.end())
            dfs(root->left, max, ans,visited);
        if(visited.find(root->right) == visited.end())
            dfs(root->right, max, ans,visited);
    }
};