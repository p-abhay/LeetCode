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
    string tree2str(TreeNode* root) {
        string bt = to_string(root->val);
        dfs(root,bt);
        return bt;
    }
    void dfs(TreeNode* root, string& bt) {
        if(root->left == nullptr && root->right != nullptr) {
            //cout<<"check"<<root->val<<"\n";
            bt += "()";
        }
            
        if(root->left) {
            bt += '(' + to_string(root->left->val);
            dfs(root->left,bt);
            bt += ')';
        }
        if(root->right) {
            bt += '(' + to_string(root->right->val);
            dfs(root->right,bt);
            bt += ')';
        }
    }
};