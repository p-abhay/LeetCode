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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();
                if(i == levelSize - 1)
                    ans.push_back(currNode->val);
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                if(currNode->right != nullptr)
                    q.push(currNode->right);
            }
        }
        return ans;
    }
};