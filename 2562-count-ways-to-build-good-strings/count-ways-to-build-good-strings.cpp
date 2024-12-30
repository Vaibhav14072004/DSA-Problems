// Approach 1 ->> Top Down DP (Recursion + Memoization)
// TC= O(N)

class Solution {
public:
    const int MOD= 1000000007;
    int solve(int currLen, int low, int high, int zero, int one, vector<int> &dp)
    {
         if(currLen > high){
            return 0;
         }

         if(dp[currLen] != -1)
         {
            return dp[currLen];
         }
         
         // if the currLen lies between low and high, add 1 
         int cnt= 0;
         if(currLen >= low && currLen <= high)
         {
            cnt= 1;
         }

         // append 1's of length one...
         cnt= (cnt+ solve(currLen+ one, low, high, zero, one, dp)) % MOD;

         // append 0's of length zero..
         cnt= (cnt+ solve(currLen+ zero, low, high, zero, one, dp)) % MOD;

        return dp[currLen]= cnt % MOD;
    }


    int countGoodStrings(int low, int high, int zero, int one){
         int currLen= 0;

         vector<int> dp(high+1, -1);
         return solve(currLen, low, high, zero, one, dp);
    }
};