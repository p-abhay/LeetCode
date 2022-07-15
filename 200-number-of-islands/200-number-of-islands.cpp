class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<int> offsets = {0, 1, 0, -1, 0};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    //cout<<islands<<" : ";
                    islands += 1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair<int,int> co = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int newi = co.first + offsets[k];
                            int newj = co.second + offsets[k+1];
                            if((newi >= 0) && (newj >= 0) && (newi < m) && (newj < n) && (grid[newi][newj]) == '1') {
                                //cout<<grid[newi][newj]<<" : ";
                                grid[newi][newj] = '0';
                                q.push({newi,newj});   
                                //cout<<newi<<","<<newj<<"\n";
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};