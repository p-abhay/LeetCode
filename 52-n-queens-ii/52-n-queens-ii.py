class Solution:
    def totalNQueens(self, n: int) -> List[List[str]]:
        
        def solve(row, cols, diagonals, anti_diagonals):
            if row == n:
                return 1
            
            ans = 0
            for col in range(n):
                curr_diag = row - col
                curr_anti_diag = row + col
                
                if col in cols or curr_diag in diagonals or curr_anti_diag in anti_diagonals:
                    continue
                    
                cols.add(col)
                diagonals.add(curr_diag)
                anti_diagonals.add(curr_anti_diag)
                
                ans += solve(row + 1, cols, diagonals, anti_diagonals)
                
                cols.remove(col)
                diagonals.remove(curr_diag)
                anti_diagonals.remove(curr_anti_diag)
                
            return ans
        
        return solve(0, set(), set(), set())
