// APPROACH 1 =>> Top Down =>> Recursion + Memoization
// TC= O(N^2)

class Solution {
public:
    int solve(int curr, int prev, vector<int> &nums,vector<vector<int>> &dp)
    {
        if(curr== nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        // include..
        int include= 0;
        if(prev== -1 || nums[curr] > nums[prev])
        {
            include= 1+ solve(curr+1,curr,nums,dp);
        }

        int exclude= solve(curr+1,prev,nums,dp);
        return dp[curr][prev+1]= max(include,exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return solve(0,-1,nums,dp);
    }
};