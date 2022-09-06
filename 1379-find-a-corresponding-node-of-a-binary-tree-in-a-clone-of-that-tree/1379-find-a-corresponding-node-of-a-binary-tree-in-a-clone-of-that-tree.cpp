/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->val == target->val)
                    return currNode;
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
        }
        return nullptr;
    }
};