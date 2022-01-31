class Solution:
    def totalNQueens(self, n: int) -> List[List[str]]:
        
        def arrange_board(board):
            new_board = []
            for row in board:
                new_board.append("".join(row))
            return new_board
        
        def solve(row, cols, diagonals, anti_diagonals, board):
            if row == n:
                ans.append(arrange_board(board))
                return
            
            for col in range(n):
                curr_diag = row - col
                curr_anti_diag = row + col
                
                if col in cols or curr_diag in diagonals or curr_anti_diag in anti_diagonals:
                    continue
                    
                cols.add(col)
                diagonals.add(curr_diag)
                anti_diagonals.add(curr_anti_diag)
                board[row][col] = "Q"
                
                solve(row + 1, cols, diagonals, anti_diagonals, board)
                
                cols.remove(col)
                diagonals.remove(curr_diag)
                anti_diagonals.remove(curr_anti_diag)
                board[row][col] = "."
        
        ans = []
        initial_board = [["."]*n for i in range(n)]
        solve(0, set(), set(), set(), initial_board)
        
        return len(ans)