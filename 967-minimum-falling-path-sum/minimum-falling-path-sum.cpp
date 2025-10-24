// Approach 3 -> Space Optimized
// TC= O(N^2)
// SC= O(N)

class Solution{
 public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> curr(m,0);
        
        for(int j=0; j<m; j++)
        {
            curr[j]= matrix[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            vector<int> next(m,0);
            for(int j=0; j<m; j++)
            {
                int down= INT_MAX;
                if(i+1< n)
                {
                    down= matrix[i][j]+ curr[j];
                }

                int leftDia= INT_MAX;
                if(i+1 < n && j-1 >= 0)
                {
                    leftDia= matrix[i][j]+ curr[j-1];
                }

                int rightDia= INT_MAX;
                if(i+1 < n && j+1 < m)
                {
                    rightDia= matrix[i][j]+ curr[j+1];
                }

                next[j]= min(down,min(rightDia,leftDia));
            }
        curr= next;  
        }
    
    int ans= INT_MAX;
    for(int j=0; j<m; j++)
    {
       ans= min(ans,curr[j]);
    }

    return ans;
  }
};




// Approach 2 -> Bottom Up
// Move in opposite direction from N-1 to 0
// TC= O(N^2)

/*

class Solution{
 public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));

        for(int j=0; j<m; j++)
        {
           dp[n-1][j]= matrix[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<m; j++)
            {
                int down= INT_MAX;
                if(i+1 < n)
                {
                   down= matrix[i][j]+ dp[i+1][j];
                } 

                int rightDia= INT_MAX;
                if(i+1 < n && j+1 < m)
                {
                    rightDia= matrix[i][j]+ dp[i+1][j+1];
                }

                int leftDia= INT_MAX;
                if(i+1 < n && j-1 >= 0)
                {
                    leftDia= matrix[i][j]+ dp[i+1][j-1];
                }
              dp[i][j]= min(down, min(rightDia,leftDia));
            }
        }

        int ans= INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans= min(ans, dp[0][j]);
        }
      return ans;  
    }
};

*/







// ---- GIVING TLE (49 / 52 testcases passed)
// Approach 1 -> Top Down
// TC= O(N^2)

/*

class Solution {
public:
    int solve(int i, int j,vector<vector<int>> &matrix, vector<vector<int>> &dp, int n, int m)
    {
        if(j< 0 || j>= m) return 1e9;
        if(i== n-1) return matrix[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down= solve(i+1,j,matrix,dp,n,m);
        int rightDia= solve(i+1,j+1,matrix,dp,n,m);
        int leftDia= solve(i+1,j-1,matrix,dp,n,m);

       return dp[i][j]= matrix[i][j] + min(down, min(rightDia,leftDia)); 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int ans= 1e9;

        vector<vector<int>> dp(n,vector<int> (m,-1));
       
       // there are variable starting and ending points, so check min from all starting points
        for(int j=0; j<m; j++)
        {
            ans= min(ans,solve(0,j,matrix,dp,n,m));
        }
      return ans;  
    }
};

*/