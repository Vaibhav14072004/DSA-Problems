// Approach 1 -> Top Down (Memoiztion)
// TC= O(N*M)
// SC= O(N*M)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n= grid.size();
        int m= grid[0].size();

        // base case
        if(i< n && j< m && grid[i][j]== 1){
            return 0;
        }

        if(i== n-1 && j== m-1){
            return 1;
        }

        if(i>=n || j>= m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down= 0,right= 0;

        if(i+1 < n){
            down= solve(i+1,j,grid,dp);
        }

        if(j+1< m){
            right= solve(i,j+1,grid,dp);
        }
    return dp[i][j]= down+ right;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(0,0,grid,dp);
    }
};