// Approach 1 -> Top Down (Memoization)
// TC= O(N* sum)

class Solution {
 public:
    bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        // base case..
        if(target== 0){
            return true;
        }

        if(i>= nums.size() || target < 0){
            return false;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        // take, notTake...
        bool take= false;
        if(nums[i] <= target)
        {
           take= solve(i+1,target-nums[i],nums,dp);
        }

        bool notTake= solve(i+1,target,nums,dp);
        
        return dp[i][target]= take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum= 0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
        }
     
        if(sum % 2 != 0){
            return false;
        }
        
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(0,sum/2,nums,dp);
    }
};