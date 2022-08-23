class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            int check[10] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') 
                    continue;
                if(check[board[i][j]-'0'])
                    return false;
                else
                    check[board[i][j]-'0'] = 1;
            }
        }
        
        for(int i = 0; i < 9; i++) {
            int check[10] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') 
                    continue;
                if(check[board[j][i]-'0'])
                    return false;
                else
                    check[board[j][i]-'0'] = 1;
            }
        }
        vector<map<int,int>> mp(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                mp[i/3*3+j/3][board[i][j]-'0'] += 1;
                //cout<<mp[i/3+j/3][board[i][j] - '0']<<"\n";
            }
        }
        // for(int i  = 0; i < 9; i++) {
        //     for(auto j : mp[i])
        //         cout<<j.first<<" "<<j.second<<"\n";
        //     cout<<"...";
        // }
        for(int i = 0; i < 9; i++) {
            for(auto j : mp[i]) {
                if(j.second > 1)
                    return false;
            }
        }
        return true;
        // for(int i = 0; i < 9; i += 3) {
        //     int k = 0;
        //     int check[10] = {0};
        //     for(int j = i; j < i + 3; j++) {
        //         for(; k < j + 3; k++) {
        //             if(board[j][k] == '.') 
        //                 continue;
        //             if(check[board[j][k]-'0'])
        //                 return false;
        //             else
        //                 check[board[j][k]-'0'] = 1;
        //         }
        //     }
        // }
        
        
        return true;
    }
};