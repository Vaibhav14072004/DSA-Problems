// Approach 3 -> Tabulation (Space Optimized)
// TC= O(N^2)
// SC= O(1)

class Solution{
  public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);

        for(int curr= n-1; curr>= 0; curr--)
        {
            for(int prev= curr-1; prev>= -1; prev--)
            {
                int include= 0;
                if(prev== -1 || nums[curr] > nums[prev])
                {
                    include= 1+ nextRow[curr+1];
                }

                int exclude= nextRow[prev+1];
                currRow[prev+1]= max(include,exclude);
            }
            nextRow= currRow;
        }
return nextRow[0];
    }
};






// Approach 2 -> Bottom Up (Tabulation)
// TC= O(N^2)
// SC= O(N^2)

// curr goes from n-1 to 0
// prev goes from curr-1 to -1

/*

class Solution{
  public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int curr= n-1; curr>=0; curr--)
        {
            for(int prev= curr-1; prev>= -1; prev--)
            {
                int include= 0;
                if(prev== -1 || nums[curr] > nums[prev])
                {
                    include= 1+ dp[curr+1][curr+1];
                }

                int exclude= dp[curr+1][prev+1];
                dp[curr][prev+1]= max(exclude,include);
            }
        }
      return dp[0][0];   
     }
};

*/








// APPROACH 1 =>> Top Down =>> Recursion + Memoization
// TC= O(N^2)

/*

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

*/