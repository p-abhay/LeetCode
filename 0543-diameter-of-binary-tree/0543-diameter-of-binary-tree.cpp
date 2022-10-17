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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        TreeNode* maxD = nullptr;
        //solve(root, diameter);
        solve1(root, diameter,maxD);
        return diameter;
    }
    
    int solve(TreeNode* root, int& diameter) {
        if(root == nullptr)
            return 0;
        
        int lh = solve(root->left, diameter);
        int rh = solve(root->right, diameter);
        
        diameter = max(diameter, (lh+rh));
        
        return 1 + max(lh,rh);
    }
    int solve1(TreeNode* root, int& diameter, TreeNode* &maxD) {
        if(root == nullptr)
            return 0;
        
        int lh = solve1(root->left, diameter, maxD);
        int rh = solve1(root->right, diameter, maxD);
        if((lh+rh) > diameter) {
            diameter = max(diameter, (lh+rh));
            maxD = root;
        }
        
        
        return 1 + max(lh,rh);
    }
};