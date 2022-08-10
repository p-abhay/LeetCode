class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        map<int, vector<int>> mp;
        for(int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int e = edges[i][1];
            mp[s].push_back(e);
            mp[e].push_back(s);
        }
        vector<bool> visited(edges.size());
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int level = q.size();
            for(int i = 0; i < level; i++) {
                int currNode = q.front();
                q.pop();
                visited[currNode] = true;
                vector<int> adj = mp[currNode];
                for(auto edge : adj) {
                    if(!visited[edge])
                        q.push(edge);
                    if(edge == destination)
                        return true;
                    
                }
            }
        }
        return false;
    }
};