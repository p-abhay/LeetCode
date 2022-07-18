class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans = 0;
        map<int, int> mp;
        for(int c1 = 0; c1 < n; c1++) {
            for(int c2 = c1; c2 < n; c2++) {
                
                mp = {{0,1}};
                int sum = 0;
                for(int row = 0; row < m; row++) {
                    sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1-1] : 0);
                    ans += (mp.find(sum-target) != mp.end() ? mp[sum-target] : 0);
                    mp[sum] += 1;
                }
                
            }
        }
        return ans;
    }
};