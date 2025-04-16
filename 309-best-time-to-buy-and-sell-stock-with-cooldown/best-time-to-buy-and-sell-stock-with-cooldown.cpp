// Approach 1 -> Top Down DP (Memoization)
// TC= O(N*2)

class Solution {
public:
    int solve(int idx, bool canBuy, vector<int> prices, vector<vector<int>> &dp)
    {
        // base case
        if(idx >= prices.size()){
            return 0;
        }

        if(dp[idx][canBuy] != -1)
        {
            return dp[idx][canBuy];
        }

        if(canBuy)
        {
            return dp[idx][canBuy]= max(-prices[idx]+ solve(idx+1,false, prices,dp), 0+ solve(idx+1,true,prices,dp));
        }
        
        // can sell
        else
        {
          return dp[idx][canBuy]= max(prices[idx]+ solve(idx+2,true, prices,dp), 0+ solve(idx+1,false, prices,dp));
        }   
    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        bool canBuy= true;
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,canBuy,prices,dp);
    }
};