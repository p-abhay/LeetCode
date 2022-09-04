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
    bool comp(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        map<int,vector<pair<int,int>>> mp;
        mp[0].push_back({root->val,0});
        
        int minCol = 0;
        int maxCol = 0;
        int level = 0;
        while(!q.empty()) {
            level += 1;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                pair<int,TreeNode*> currNode = q.front();
                q.pop();
                int col = currNode.first;
                TreeNode* node = currNode.second;
                //mp[currNode.first] = currNode.second->val;
                if(node->left) {
                    mp[col-1].push_back({node->left->val,level});
                    q.push({col-1,node->left});
                    minCol = min(minCol, col-1);
                }
                if(node->right) {
                    mp[col+1].push_back({node->right->val,level});
                    q.push({col+1,node->right});
                    maxCol = max(maxCol, currNode.first+1);
                }
            }
        }
        
        for(int i = minCol; i <= maxCol; i++) {
            vector<pair<int,int>> vals = mp[i];
            sort(vals.begin(),vals.end(),[&](const pair<int,int> a, const pair<int,int> b) {
                                            if(a.second == b.second)
                                                return a.first < b.first;
                                            return a.second < b.second;
                                        });
            vector<int> v;
            for(auto i : vals)
                v.push_back(i.first);
            ans.push_back(v);
        }
        return ans;
    }
};