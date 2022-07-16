class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1000000007;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        int paths = 0;
         for (int moves = 1; moves <= maxMove; moves++) {
          vector<vector<int>> temp(m, vector<int>(n));
          for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
              if (i == m - 1) paths = (paths + dp[i][j]) % mod;
              if (j == n - 1) paths = (paths + dp[i][j]) % mod;
              if (i == 0) paths = (paths + dp[i][j]) % mod;
              if (j == 0) paths = (paths + dp[i][j]) % mod;
              temp[i][j] = (
                  ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % mod +
                  ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % mod
              ) % mod;
            }
          }
             dp = temp;
        }
        return paths;
    }
};