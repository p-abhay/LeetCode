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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root == nullptr)
            return zigzag;
        
        list<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> currLevel;
            if(level % 2 == 0) {
                for(int i = 0; i < levelSize; i++) {
                    TreeNode* currNode = q.back();
                    q.pop_back();
                    if(currNode->left != nullptr)
                        q.push_front(currNode->left);
                    if(currNode->right != nullptr)
                        q.push_front(currNode->right);
                    
                    
                    
                    currLevel.push_back(currNode->val);
                }
            }
            else {
                for(int i = 0; i < levelSize; i++) {
                    TreeNode* currNode = q.front();
                    q.pop_front();
                    if(currNode->right != nullptr)
                        q.push_back(currNode->right);
                    if(currNode->left != nullptr)
                        q.push_back(currNode->left);

                    currLevel.push_back(currNode->val);
                }
            }
            zigzag.push_back(currLevel);
            level += 1;
        }
//         queue<TreeNode*> q;
//         stack<TreeNode*> s;
//         q.push(root);
//         s.push(root);
//         int level = 0;
//         while(!q.empty() || !s.empty())
//         {
//             int qSize = q.size();
//             int sSize = s.size();
//             vector<int> currLevel;
//             if(level % 2 == 0) {
//                 for(int i = 0; i < qSize; i++) {
//                     TreeNode* currNode = q.front();
//                     q.pop();
//                     if(currNode->right != nullptr) {
//                         s.push(currNode->right);
//                         q.push(currNode->right);
//                     }
                        
//                     if(currNode->left != nullptr) {
//                         s.push(currNode->left);
//                         q.push(currNode->left);
//                     }
                    
//                     currNode = s.top();
//                     s.pop();
//                     currLevel.push_back(currNode->val);
//                     //cout<<currNode->val<<"-2 ";
//                 }
//             }
//             else {
//                 for(int i = 0; i < sSize; i++) {
//                     TreeNode* currNode = s.top();//q.front();
//                     s.pop();
//                     if(currNode->left != nullptr) {
//                         q.push(currNode->left);
//                         s.push(currNode->left);
//                     }
                        
//                     if(currNode->right != nullptr) {
//                         q.push(currNode->right);
//                         s.push(currNode->right);
//                     }
                        
                    
//                     currNode = q.front();
//                     q.pop();
//                     currLevel.push_back(currNode->val);
//                     //cout<<currNode->val<<"-1 ";
//                 }
//             }
//             zigzag.push_back(currLevel);
//             level += 1;
//         }
        return zigzag;
    }
};