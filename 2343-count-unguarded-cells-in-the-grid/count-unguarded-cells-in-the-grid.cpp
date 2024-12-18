// TC= O(N*M) + O[G* (M+N)] 
 
class Solution {
public:

// TC= O(M+N)
    void DFS(int i, int j, vector<vector<int>> &grid, int m, int n)
    {
        // mark entire row as guarded...
        // left row
        for(int col= j-1; col>=0; col--)
        { 
            if(grid[i][col]== 2 || grid[i][col]== 3){
                break;
            }
           grid[i][col]= 0;
        }

        // right row
        for(int col= j+1; col<n; col++)
        {
            if(grid[i][col]== 2 || grid[i][col]== 3){
                break;
            }
            grid[i][col]= 0;
        }

        // mark entire col as guarded...
        // up column
        for(int row= i-1; row>=0; row--)
        {
            if(grid[row][j]== 2 || grid[row][j]== 3){
                break;
            }
            grid[row][j]= 0;
        }

        // down column
        for(int row= i+1; row<m; row++)
        {
            if(grid[row][j]== 2 || grid[row][j]== 3){
                break;
            }
            grid[row][j]= 0;
        }
    }


    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
        vector<vector<int>> grid(m, vector<int> (n, 1));

        // mark all cells with walls as 2
        for(vector<int> it: walls){
            int row= it[0];
            int col= it[1]; 
            grid[row][col]= 2;
        }

        // mark all cells with guard as 3
        for(vector<int> &itr: guards){
            int row= itr[0];
            int col= itr[1];
            grid[row][col]= 3;
        }

        // mark the whole row and col as guarded
        for(vector<int> &it: guards)
        {
            int row= it[0];
            int col= it[1];
            DFS(row,col,grid,m,n);
        }

        int cnt= 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(grid[i][j]== 1){
                 cnt++;
               }
            }
        }
       return cnt; 
    }
};