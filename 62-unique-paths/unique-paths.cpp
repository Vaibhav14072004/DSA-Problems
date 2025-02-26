// Approach 2.2 ->> Bottom Up
// TC= O(N*M)


class Solution{
public:
   int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int> (n,0));
       dp[m-1][n-1]= 1;

       for(int i=m-1; i>=0; i--)
       {
          for(int j= n-1; j>=0; j--)
          {
              if(i== m-1 && j== n-1) continue;
              
              // moving down..
              if(i+1 < m) 
              {
                 dp[i][j]+= dp[i+1][j];
              }

              // moving right
              if(j+1 < n)
              {
                 dp[i][j]+= dp[i][j+1];
              }
          }
       }
     return dp[0][0];  
   }
};








// Approach 2.1 -> Bottom Up  
// TC= O(N*M)

/*

class Solution{
public:
   int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int> (n,0));

       dp[0][0]= 1;
       for(int i=0; i<m; i++)
       {
           for(int j=0; j<n; j++)
           {
               if(i==0 && j== 0) continue;

               // moving up...
               int up= 0,left= 0;
               
               if(i-1 >= 0) up= dp[i-1][j];
               if(j-1 >= 0) left= dp[i][j-1];

               dp[i][j]= up+ left;
           }
       }
     return dp[m-1][n-1];  
   }
};

*/








// Approach 1 -> Top Down
// TC= O(M*N)
// SC= O(M*N) + O(M+N)

/*

class Solution {
public:
    int solve(int i, int j,int m, int n, vector<vector<int>> &dp)
    {
        // base case
        if(i== m-1 && j== n-1) return 1;
        if(i >= m || j >= n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int down= solve(i+1,j,m,n,dp);
        int right= solve(i,j+1,m,n,dp);
        return dp[i][j]= down+right; 
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,m,n,dp);
    }
};

*/