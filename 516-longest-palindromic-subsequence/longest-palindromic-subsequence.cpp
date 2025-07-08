// Approach 1 -> Top Down (Memoization)
// TC= O(N*M)

class Solution {
public:
    int solve(int i, int j, string &str, vector<vector<int>> &dp)
    {
        // base case
        if(i> j){
           return 0;
        }

        if(i== j){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(str[i]== str[j])
        {
            dp[i][j]= 2+ solve(i+1,j-1,str,dp);
        }
        else
        {
            dp[i][j]= max(solve(i+1,j,str,dp), solve(i,j-1,str,dp));
        }
     return dp[i][j];   
    }

    int longestPalindromeSubseq(string str) {
        int n= str.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(0,n-1,str,dp);
    }
};