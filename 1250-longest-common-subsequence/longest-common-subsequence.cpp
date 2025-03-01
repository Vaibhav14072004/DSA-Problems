// Approach 1 -> Top Down (Memoization)
// TC= O(N*M)
// SC= O(N*M) + O(N+M) for recursive stack space

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