class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {
        for (int i = 0; i < 9; i++)
        {

            // row check
            if (board[row][i] == val)
            {
                return false;
            }

            // column check
            if (board[i][col] == val)
            {
                return false;
            }

            // checking 3*3 matrix
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isSafe(row, col, board, val))
                        {
                            board[row][col] = val;

                            /*
                             for further recursions to take place =>>>
                             bool nextRecursion = solve(board); and now check
                             if(nextRecursion){
                                  return true;
                             }
                             or we can also directly pass it ....
                            */

                            // for further recursions to take place =>>>
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.'; // Backtrack
                            }
                        }
                    }
                    return false; // No valid value found, backtrack
                }
            }
        }
        return true; // All cells are filled
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
