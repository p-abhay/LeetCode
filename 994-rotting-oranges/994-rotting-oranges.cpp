class Node {
    public:
        int x;
        int y;
        int time;
        Node(int x,int y,int time) {
            this->x = x;
            this->y = y;
            this->time = time;
        }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<Node> q;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j  < cols; j++) {
                if(grid[i][j] == 2) {
                    Node node = Node(i, j, 0);
                    q.push(node);
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            Node currNode = q.front();
            q.pop();
            int x = currNode.x;
            int y = currNode.y;
            int time = currNode.time;
            
            if(x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                Node node = Node(x - 1, y, time + 1);
                q.push(node);
                ans = time + 1;
            }
            
            if(x + 1 < rows && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                Node node = Node(x + 1, y, time + 1);
                q.push(node);
                ans = time + 1;
            }
            
            if(y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                Node node = Node(x, y - 1, time + 1);
                q.push(node);
                ans = time + 1;
            }
            
            if(y + 1 < cols && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                Node node = Node(x, y + 1, time + 1);
                q.push(node);
                ans = time + 1;
            }
            
        }
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j  < cols; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
        
    }
};