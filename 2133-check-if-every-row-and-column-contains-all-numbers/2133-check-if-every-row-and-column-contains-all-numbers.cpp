class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k = n + 1;
        for(int i = 0; i < n; i++) {
            int check[101] = {0};
            for(int j = 0; j < n; j++) {
                if(check[matrix[i][j]])
                    return false;
                check[matrix[i][j]] = 1;
            }
            for(int j = 1; j < n; j++) {
                if(!check[j])
                    return false;
            }
        }
        
         for(int i = 0; i < n; i++) {
            int check[101] = {0};
            for(int j = 0; j < n; j++) {
                if(check[matrix[j][i]])
                    return false;
                check[matrix[j][i]] = 1;
            }
            for(int j = 1; j < n; j++) {
                if(!check[j])
                    return false;
            }
        }
        return true;
    }
};