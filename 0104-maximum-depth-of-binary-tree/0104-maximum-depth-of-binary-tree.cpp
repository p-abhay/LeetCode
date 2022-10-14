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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int depth = 0;
        bfs(root,depth);
        return depth;
    }
    void bfs(TreeNode* root,int& depth) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            depth += 1;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
        }
    }
};