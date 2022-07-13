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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        else if(p == nullptr || q == nullptr)
            return false;
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty())
        {
            int size1 = q1.size();
            int size2 = q2.size();
            if(size1 != size2) {
                //cout<<"1";
                return false;
            }
                
            for(int i = 0; i < size1; i++) {
                TreeNode* currNode1 = q1.front();
                q1.pop();
                TreeNode* currNode2 = q2.front();
                q2.pop();
                if(currNode1->val != currNode2->val) {
                    //cout<<"2";
                    return false;
                }
                
                if(currNode1->left != nullptr && currNode2->left != nullptr) {
                    if(currNode1->left->val != currNode2->left->val) {
                        //cout<<"3";
                        return false;
                    }
                        
                    q1.push(currNode1->left);
                    q2.push(currNode2->left);
                }
                else if(currNode1->left == nullptr && currNode2->left == nullptr);
                else {
                    //cout<<"4";
                    return false;
                }
                
                if(currNode1->right != nullptr && currNode2->right != nullptr) {
                    if(currNode1->right->val != currNode2->right->val) {
                        //cout<<"5";
                        return false;
                    }
                    q1.push(currNode1->right);
                    q2.push(currNode2->right);
                }
                else if(currNode1->right == nullptr && currNode2->right == nullptr);
                else {
                    //cout<<"6";
                    return false;
                }
            }
        }
        return true;
    }
};