// Approach 1 -> Top Down (Recursion + Memoization)
// TC= O(N*M)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
    {
        if(i<0 || i >=n || j<0 || j>= m)
        {
            return 0;
        }

        if(matrix[i][j]== 0)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right= solve(i,j+1,matrix,n,m,dp);
        int diagonal= solve(i+1,j+1,matrix,n,m,dp);
        int down= solve(i+1,j,matrix,n,m,dp);

        return dp[i][j]= 1 + min(right, min(diagonal, down));
    }
  

    int countSquares(vector<vector<int>>& matrix) {
        int n= matrix.size();     // rows
        int m= matrix[0].size();  // col
        
        int ans= 0;
        vector<vector<int>> dp(n,vector<int> (m, -1));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]== 1)
                {
                    ans+= solve(i,j,matrix,n,m,dp);
                }
            }
        }
    return ans;
    }
};