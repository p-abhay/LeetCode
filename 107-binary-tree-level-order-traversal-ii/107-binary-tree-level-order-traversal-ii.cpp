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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        deque<vector<int>> dq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> currList;
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();
                currList.push_back(currNode->val);
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                if(currNode->right != nullptr)
                    q.push(currNode->right);
            }
            dq.push_front(currList);
        }
        while(!dq.empty())
        {
            vector<int> currList = dq.front();
            dq.pop_front();
            ans.push_back(currList);
        }
        return ans;
    }
};