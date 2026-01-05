// Approach 1 -> Top Down
// TC= O(N^2)

class Solution {
public:
    int solve(int i,int j,string &str,vector<vector<int>> &dp,int n)
    {
        if(i>= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(str[i]== str[j])
        {
            return dp[i][j]= solve(i+1,j-1,str,dp,n);
        }

        return dp[i][j]= 1 + min(solve(i+1,j,str,dp,n), solve(i,j-1,str,dp,n));
    }

    int minInsertions(string str) {
        int n= str.length();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        return solve(0,n-1,str,dp,n);
    }
};