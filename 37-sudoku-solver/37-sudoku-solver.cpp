/*class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> grid(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                grid[i/3*3+j/3].insert(board[i][j]);
                rows[i].insert(board[i][j]);
                cols[i].insert(board[i][j]);
            }
        }
        solve(0,board,rows,cols,grid);
    }
    void solve(int col, vector<vector<char>>& board, vector<set<char>>& rows, vector<set<char>>& cols, vector<set<char>>& grid) {
        if(col == 9)
            return;
        for(int row = 0; row < 9; row++) {
            if(board[row][col] == '.') {
                cout<<row<<" "<<col<<"\n";
                for(int k = 1; k <= 9; k++) {
                    if(rows[row].find('0' + k) == rows[row].end() && 
                       cols[col].find('0' + k) == cols[col].end() && 
                       grid[row/3*3+col/3].find(k) == grid[row/3*3+col/3].end()) {
                        board[row][col] = '0' + k;
                        rows[row].insert('0' + k);
                        cols[col].insert('0' + k);
                        grid[row/3*3+col/3].insert('0' + k);
                        solve(col+1,board,rows,cols,grid);
                        rows[row].erase('0' + k);
                        cols[col].erase('0' + k);
                        grid[row/3*3+col/3].erase('0' + k);
                    }
                }
            }
        }
    }
};*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> grid(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                grid[i/3*3+j/3].insert(board[i][j]);
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
            }
        }
        for(auto i : grid) {
            for(auto j : i)
                cout<<j<<" ";
            cout<<"\n";
        }
        solve(board,rows,cols,grid);
    }
    bool solve(/*int col,*/ vector<vector<char>>& board, vector<set<char>>& rows, vector<set<char>>& cols, vector<set<char>>& grid) {
        //if(col == 9)
         //   return true;
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++)
            if(board[row][col] == '.') {
                for(int k = 1; k <= 9; k++) {
                    if(rows[row].find('0'+ k) == rows[row].end() && 
                       cols[col].find('0' + k) == cols[col].end() && 
                       grid[row/3*3+col/3].find('0'+k) == grid[row/3*3+col/3].end()) {
                        rows[row].insert('0'+k);
                        cols[col].insert('0'+k);
                        grid[row/3*3+col/3].insert('0'+k);
                        board[row][col] = '0' + k;
                        if(solve(board,rows,cols,grid))
                            return true;
                        else {
                            rows[row].erase('0'+k);
                            cols[col].erase('0'+k);
                            grid[row/3*3+col/3].erase('0'+k);
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
};