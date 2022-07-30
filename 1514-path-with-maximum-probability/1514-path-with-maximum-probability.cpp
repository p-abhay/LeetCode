class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int e = edges[i][1];
            double prob = succProb[i];
            adj[s].push_back(make_pair(e,prob));
            adj[e].push_back({s,prob});
        }
        vector<double> prob(n,0.0);
        priority_queue<pair<double,int>> pq;
        prob[start] = 1.0;
        pq.push({prob[start],start});
        //vector<int> visited(n,0);
        while(!pq.empty())
        {
            int node = pq.top().second;
            double probb = pq.top().first;
            pq.pop();
            //if(!visited[node]) {
                //visited[node]++;
                for(int i = 0; i < adj[node].size(); i++) {
                    int currNode = adj[node][i].first;
                    double currProb = adj[node][i].second;
                    if(prob[currNode] < (probb*currProb)) {
                        prob[currNode] = probb*currProb;
                        pq.push({prob[currNode],currNode});
                    }
                }
            //}
            
        }
        return prob[end];
    }
};