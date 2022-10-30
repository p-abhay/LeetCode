class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        int min_steps = INT_MAX,curr_steps = -1;
        queue<pair<pair<int,int>,int>> q; 
        q.push({{0,0},0});
        while(!q.empty()) {
            int levelSize = q.size();
            curr_steps += 1;
            for(int i = 0; i < levelSize; i++) {
                auto node = q.front();
                q.pop();
                int x = node.first.first;
                int y = node.first.second;
                int cnt_k = node.second;
                if(x == (m-1) && y == (n-1)) {
                    min_steps = min(min_steps,curr_steps);
                }
                if(x+1 < m && (vis[x+1][y] == -1 || vis[x+1][y] > cnt_k)) {
                    if(grid[x+1][y] == 0) {
                        q.push({{x+1,y},cnt_k});
                        vis[x+1][y] = cnt_k;
                    }
                    else if(grid[x+1][y] == 1 && cnt_k < k) {
                        q.push({{x+1,y},cnt_k+1});
                        vis[x+1][y] = cnt_k+1;
                    }
                    else {
                        ;
                    }
                }
                if(y+1 < n && (vis[x][y+1] == -1 || vis[x][y+1] > cnt_k)) {
                    if(grid[x][y+1] == 0) {
                        q.push({{x,y+1},cnt_k});
                        vis[x][y+1] = cnt_k;
                    }
                    else if(grid[x][y+1] == 1 && cnt_k < k) {
                        q.push({{x,y+1},cnt_k+1});
                        vis[x][y+1] = cnt_k+1;
                    }
                    else {
                        ;
                    }
                }
                if(x-1 >= 0 && (vis[x-1][y] == -1 || vis[x-1][y] > cnt_k)) {
                    if(grid[x-1][y] == 0) {
                        q.push({{x-1,y},cnt_k});
                        vis[x-1][y] = cnt_k;
                    }
                    else if(grid[x-1][y] == 1 && cnt_k < k) {
                        q.push({{x-1,y},cnt_k+1});
                        vis[x-1][y] = cnt_k+1;
                    }
                    else {
                        ;
                    }
                }
                if(y-1 >= 0 && (vis[x][y-1] == -1 || vis[x][y-1] > cnt_k)) {
                    if(grid[x][y-1] == 0) {
                        q.push({{x,y-1},cnt_k});
                        vis[x][y-1] = cnt_k+1;
                    }
                    else if(grid[x][y-1] == 1 && cnt_k < k) {
                        q.push({{x,y-1},cnt_k+1});
                        vis[x][y-1] = cnt_k+1;
                    }
                    else {
                        ;
                    }
                }
            }
        }
        if(min_steps == INT_MAX)
            return -1;
        return min_steps;
    }
};