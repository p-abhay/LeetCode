/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> nary;
        if(root == nullptr)
            return nary;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel;
            for(int i = 0; i < levelSize; i++) {
                Node* currNode = q.front();
                q.pop();
                vector<Node*> child = currNode->children;
                for(auto node : child) {
                    if(node)
                        q.push(node);
                }
                currLevel.push_back(currNode->val);
            }
            nary.push_back(currLevel);
        }
        return nary;
    }
};