// Approach 3 -> Space Optimized
// TC= O(N*M)
// SC= O(1)

class Solution{
 public:
     int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        int len= max(n,m);

        vector<int> curr(len+1,0);
        vector<int> next(len+1,0);

        for(int i=n-1; i>=0; i--)
        {
            for(int j= m-1; j>=0; j--)
            {
                if(text1[i]== text2[j])
                {
                    curr[j]= 1 + next[j+1];
                }
                else
                {
                    curr[j]= max(next[j], curr[j+1]);
                }
            }
           next= curr; 
        }
     return next[0];
     }
};






// Approach 2 -> Bottom Up (Tabulation)
// TC= O(N*M)
// SC= O(N*M) 

/*

class Solution{
 public:
     int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j= m-1; j>=0; j--)
            {
                if(text1[i]== text2[j])
                {
                    dp[i][j]= 1 + dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
     return dp[0][0];
     }
};

*/






// Approach 1 -> Top Down (Memoization)
// TC= O(N*M)
// SC= O(N*M) + O(N+M) for recursive stack space

/*

class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp, int n, int m)
    {
        // base case
        if(i >= n || j>= m)
        {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
         
        if(text1[i]== text2[j])
        {
            dp[i][j]= 1 + solve(i+1,j+1,text1,text2,dp,n,m);
        }
        else
        {
            dp[i][j]= max(solve(i,j+1,text1,text2,dp,n,m), solve(i+1,j,text1,text2,dp,n,m));
        }
    return dp[i][j];
    }
 

    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(0,0,text1,text2,dp,n,m);
    }
};

*/