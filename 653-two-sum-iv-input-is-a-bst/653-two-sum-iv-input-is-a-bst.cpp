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
    int l = 0;
    bool findTarget(TreeNode* root, int k) {
        //vector<int> inOrd;
        bool ans = false;
        map<int, int> mp;
        inOrder(root, mp, ans, k);
        
        /*for(int i = 0; i < inOrd.size(); i++) {
            if(mp.find(k - inOrd[i]) != mp.end())
                return true;
            else
                mp[inOrd[i]] = i;
        }*/
        return ans;
    }
private:
    void inOrder(TreeNode* root, map<int, int>& mp, bool &ans, int k) {
        if(root == nullptr)
            return;
        inOrder(root->left, mp, ans, k);
        if(mp.find(k - root->val) != mp.end()) {
            ans = true;
            return;
        }
        else
            mp[root->val] = l++;
            
        inOrder(root->right, mp, ans, k);
    }
};