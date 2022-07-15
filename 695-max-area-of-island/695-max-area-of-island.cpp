class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    maxArea = max(maxArea, solve(i, j, grid));
            }
        }
        return maxArea;
    }
    int solve(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >=n || !grid[i][j])
            return 0;
        grid[i][j] = 0;
        return 1 + solve(i-1,j,grid) + solve(i,j-1,grid) + solve(i,j+1,grid) + solve(i+1,j,grid);
    }
};