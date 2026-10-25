// Approach 1 -> Memoization
// TC= O(N*2)

class Solution {
public:
    int solve(int i, bool canBuy, vector<int>&prices,vector<vector<int>> &dp,int n)
    {
        if(i >= n) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int ans= 0;

        // canBuy= 1, we can buy...
        if(canBuy)
        {
            int buy= -prices[i]+ solve(i+1,0,prices,dp,n);
            int notBuy= solve(i+1,1,prices,dp,n);
            ans= max(ans,max(buy,notBuy));
        }
        
        // we have to sell, canBuy= 0
        else
        {
           int sell= prices[i]+ solve(i+1,1,prices,dp,n);
           int notSell= solve(i+1,0,prices,dp,n);
           ans= max(ans,max(sell,notSell));
        }
        return dp[i][canBuy]= ans;
    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n== 0) return 0;

        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,prices,dp,n);
    }
};