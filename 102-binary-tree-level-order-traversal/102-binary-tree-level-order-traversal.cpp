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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> currList;
            while(levelSize != 0)
            {
                TreeNode* node = q.front();
                q.pop();
                currList.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
                levelSize--;
            }
            ans.push_back(currList);
        }
        return ans;
    }
};