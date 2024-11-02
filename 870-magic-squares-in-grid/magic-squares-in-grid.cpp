// Approach 1 -> Top Down(Recursion + Memoization)
// TC= O(N*M)
// SC= O(3*3) ->> O(1)

class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &grid)
    {
        unordered_set<int> st;

        // first check all numbers in 3*3 sub-matrix should be unique.. and should lie b/w 0 to 9
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
               int no= grid[row+i][col+j];

               if(no < 1|| no > 9 || st.find(no) != st.end())
               { 
                  return false; 
               }
               else
               {
                  st.insert(no);
               }
            }
        }

        // now check for sum of all rows and col should be same
        int sum= grid[row][col] + grid[row][col+1]+ grid[row][col+2];
   
        for(int i=0; i<3; i++)
        {
            // To check all rows...
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != sum)
            {
                return false;
            }
            
            // To check all columns...
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum)
            {
                return false;
            }
        }

        // Now Check sum of front diagonal...
        if(grid[row][col]+ grid[row+1][col+1] + grid[row+2][col+2] != sum)
        {
            return false;
        }

        // Now check sum of back diagonal...
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum)
        {
            return false;
        }
    return true;
    }


    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();
        
        int ans= 0;

        // max index can go up to row-3, col-3 to be a square..
        for(int i=0; i<= rows-3; i++)
        {
            for(int j=0; j<= cols-3; j++)
            {
                ans+= solve(i,j,grid);
            }
        }
      return ans;  
    }
};