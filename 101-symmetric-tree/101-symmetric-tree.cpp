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
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left == nullptr && right == nullptr)
            return true;
        return check(left, right);
    }
    bool check(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr)
            return true;
        else if(left == nullptr || right == nullptr)
            return false;
        else if(left->val == right->val)
            return check(left->left, right->right) && check(left->right, right->left);
        // cout<<left->val<<" "<<right->val;
        // cout<<"checkc";
        return false;
//         else
//             return false;
            
//         return check(left->left, right->left) && check(left->right, right->left);
    }
};