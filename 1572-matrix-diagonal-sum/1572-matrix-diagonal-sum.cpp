class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int k = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += mat[i][k];
            k += 1;
        }
        k -= 1;
        for(int i = 0; i < n; i++) {
            ans += mat[i][k];
            k -= 1;
        }
        if(n % 2 != 0) {
            ans -= mat[n/2][n/2];
        }
        return ans;
    }
};