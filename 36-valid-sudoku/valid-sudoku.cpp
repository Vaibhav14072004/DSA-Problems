    // Approach 1 => Using unordered_set...
    // Time complexity (TC):-  O(9^2)=O(1)
    // Space complexity (SC) :- O(9*3)= O(1)
    
    class Solution{
    public:
      bool isValidSudoku(vector<vector<char>>& board) {
         for(int i=0; i<9; i++)
         {
             unordered_set<char> row;
             unordered_set<char> col;
             unordered_set<char> subgrid;

            for(int j=0; j<9; j++)
            {
                // row.count(board[i][j]) > 0 => Return false
                if(board[i][j] != '.' && row.find(board[i][j]) != row.end())
                {
                    return false;
                }

                row.insert(board[i][j]);
            
            // for Row => [i][j] and for Column => [j][i]
                if(board[j][i] != '.' && col.find(board[j][i]) != col.end())
                {
                    return false;
                }
                
                col.insert(board[j][i]);
            
            int subgrid_x= 3*(i/3)+ j/3;
            int subgrid_y= 3*(i%3) + j%3;

                if(board[subgrid_x][subgrid_y] != '.' && subgrid.find(board[subgrid_x][subgrid_y]) != subgrid.end())
                {
                    return false;
                }

                subgrid.insert(board[subgrid_x][subgrid_y]);
            }
          }
               return true;
         }
            };
