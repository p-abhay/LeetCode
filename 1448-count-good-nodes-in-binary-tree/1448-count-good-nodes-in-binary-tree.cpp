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
        dfs(root,max,ans);
        return ans;
    }
    void dfs(TreeNode* root, int max, int& ans) {
        if(root == nullptr)
            return;
        if(root->val >= max) {
            max = root->val;
            ans += 1;
        }
        dfs(root->left, max, ans);
        dfs(root->right, max, ans);
    }
};