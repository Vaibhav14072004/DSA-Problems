// Approach 2 ->> Bottom Up (Tabulation)
// TC= O(N^2) + O(N log N)

class Solution{
public:
   vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n= nums.size();
          sort(nums.begin(),nums.end());

          vector<int> dp(n,1);
          vector<int> prev(n,-1);

          int maxLen= 1;
          int maxIdx= 0;

          for(int i=1; i<n; i++)
          {
             for(int j=0; j<i; j++)
             {
                 if(nums[i] % nums[j]== 0)
                 {
                     if(dp[i] < dp[j]+1)
                     {
                         dp[i]= dp[j]+1;
                         prev[i]= j;
                     }
                     if(maxLen < dp[i])
                     {
                        maxLen= dp[i];
                        maxIdx= i;
                     }
                 }
             }
          }

          vector<int> ans;
          while(maxIdx != -1)
          {
              ans.push_back(nums[maxIdx]);
              maxIdx= prev[maxIdx];
          }
   return ans;
   }
};








//  ------ TLE for 2 testcases --------
// Approach 1 -> Top Down Approach (Recursion+ Memoization)
// TC= O(N^2) + O(N log N)

/*

class Solution {
public:
    void solve(int i,int prev,vector<int> &nums,vector<int> &temp, vector<int> &ans, vector<vector<int>> &dp)
    {
        // base case
        if(i >= nums.size())
        { 
            if(temp.size() > ans.size()){
                ans= temp;
            }
            return;
        }

        if(dp[i][prev+1] != -1){
            return;
        }
        
        // take
        if(prev== -1 || nums[i] % nums[prev]== 0)
        {
            temp.push_back(nums[i]);
            solve(i+1, i, nums, temp, ans,dp);

            // backtracking...
            temp.pop_back();
        }

        // Not take
        solve(i+1, prev, nums, temp, ans,dp);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n= nums.size();
          sort(nums.begin(),nums.end());

          vector<int> ans;
          vector<int> temp;
          int prev= -1;

          vector<vector<int>> dp(n,vector<int> (n+1,-1));
          solve(0,prev,nums,temp,ans,dp);
          return ans;
    }
};

*/