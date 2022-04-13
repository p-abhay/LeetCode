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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrd;
        inOrder(root, inOrd);
        map<int, int> mp;
        for(int i = 0; i < inOrd.size(); i++) {
            if(mp.find(k - inOrd[i]) != mp.end())
                return true;
            else
                mp[inOrd[i]] = i;
        }
        return false;
    }
private:
    void inOrder(TreeNode* root, vector<int>& inOrd) {
        if(root == nullptr)
            return;
        inOrder(root->left, inOrd);
        inOrd.push_back(root->val);
        inOrder(root->right, inOrd);
    }
};