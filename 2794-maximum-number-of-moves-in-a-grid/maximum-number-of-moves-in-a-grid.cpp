/* 
We can move in three directions---
    1
   /
  /-------- 2
  \ 
   \ 
     3

*/

// Approach 1 -> Top Down (Recursion + Memoization)
// TC= O(N)
// SC= O(N)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
    {
        // base case
        if(i < 0 || i>= n || j < 0 || j>= m)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int dir1= 0, dir2= 0, dir3= 0, ans= 0;
        if(i-1 >=0 && j+1 < m && grid[i][j] < grid[i-1][j+1])
        {
            ans= max(ans, 1 + solve(i-1,j+1,grid,n,m,dp)); 
        }

        if(j+1< m && grid[i][j] < grid[i][j+1])
        {
            ans= max(ans, 1 + solve(i,j+1,grid,n,m,dp));
        }

        if(i+1< n && j+1< m && grid[i][j] < grid[i+1][j+1])
        {
            ans= max(ans, 1 + solve(i+1,j+1,grid,n,m,dp));
        }

       return dp[i][j]= ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n= grid.size();    // row
        int m= grid[0].size(); // col
        
        int ans= 0;
        vector<vector<int>> dp(n, vector<int> (m,-1));
       
        // start at any cell in the first column 
        for(int i=0; i<n; i++)
        {
           ans= max(ans, solve(i,0,grid,n,m,dp));
        }
        return ans;
    }
};