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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        vector<TreeNode*> preOrder;
        preorder(root,preOrder);
        int i = 0;
        for(; i < preOrder.size() - 1; i++) {
            TreeNode* currNode = preOrder[i];
            TreeNode* nextNode = preOrder[i+1];
            currNode->left = nullptr;
            currNode->right = nextNode;
        }
        TreeNode* lastNode = preOrder[i];
        lastNode->left = nullptr;
        lastNode->right = nullptr;
    }
    void preorder(TreeNode* root,vector<TreeNode*>& preOrder) {
        if(root == nullptr)
            return;
        preOrder.push_back(root);
        preorder(root->left, preOrder);
        preorder(root->right, preOrder);
    }
};