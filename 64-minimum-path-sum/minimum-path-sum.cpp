// Approach 1 -> Top Down
// TC= O(N*M)

class Solution {
public:
    int solve(int i, int j,vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp)
    {
        // base case
        if(i>= n || j >= m) return INT_MAX;
        if(i== n-1 && j== m-1) return grid[n-1][m-1];

        if(dp[i][j] != -1) return dp[i][j];

        int down= INT_MAX;
        if(i+1 < n)
        {
            down= grid[i][j]+ solve(i+1,j,grid,n,m,dp);
        }

        int right= INT_MAX;
        if(j+1 < m)
        {
            right= grid[i][j]+ solve(i,j+1,grid,n,m,dp);
        }
        return dp[i][j]= min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(0,0,grid,n,m,dp);  
    }
};