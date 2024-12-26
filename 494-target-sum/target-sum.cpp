// Approach 2.2 -> DP + Using map instead of 2D vector
// TC= O(N* totalSum)

class Solution {
public:
   int solve(int index, vector<int> &nums, int currSum, int &target, unordered_map<string,int> &mp)
   {
       // base case
       if(index== nums.size()){
           if(currSum== target)
           {
             return 1;
           }
           else
           {
            return 0;
           }
       }
       
       string currString= to_string(index)+ '_' + to_string(currSum);

       // if this state is already seen, directly return .
       if(mp.count(currString))
       {
          return mp[currString];
       }

       int plus= solve(index+1,nums, currSum+nums[index], target, mp);
       int minus= solve(index+1,nums, currSum-nums[index], target, mp);

       string temp= to_string(index) + '_' + to_string(currSum);
       return mp[temp]= plus+ minus;
   }


   int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int currSum= 0;

        unordered_map<string,int> mp;
        return solve(0,nums,currSum, target, mp);
    }
};










// Approach 2.1 -> Top Down DP (Memoization)
// TC= O[N* (2* TotalSum + 1)] ->> O(N* totalSum)

/*

class Solution{
 public: 
    int solve(int index, vector<int> &nums, int currSum,int &totalSum,int &target, vector<vector<int>> &dp)
    {
        if(index== nums.size())
        {
            return (currSum== target) ? 1 : 0;
        }
        
        // currSum can be -ve, so we add totalSum in it to store in 2D vector
        if(dp[index][currSum+ totalSum] != -1) 
        {
            return dp[index][currSum+ totalSum];
        }

        int plus= solve(index+1, nums, currSum+ nums[index], totalSum, target,dp);
        int minus= solve(index+1, nums, currSum- nums[index], totalSum, target, dp);

        return dp[index][currSum+ totalSum]= plus+ minus;
    }
     

     int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int totalSum= 0;

        for(int i=0; i<n; i++){
          totalSum+= nums[i];
        }
        
        // currSum can be -ve, so we cannot store it directly in 2D vector as index cannot be -ve
        vector<vector<int>> dp(n+1, vector<int> (2*totalSum+1, -1));

        int currSum= 0;
        return solve(0,nums,currSum,totalSum,target,dp);
     }
};

*/






// Approach 1 -> Exploring both combinations for every index
// TC= O(2^N)

/*

class Solution {
public:
   int solve(int index, vector<int> &nums, int currSum, int &target)
   {
       // base case
       if(index== nums.size()){
           if(currSum== target)
           {
             return 1;
           }
           else
           {
            return 0;
           }
       }

       int plus= solve(index+1,nums, currSum+nums[index], target);
       int minus= solve(index+1,nums, currSum-nums[index], target);
       return plus+ minus;
   }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int currSum= 0;
        return solve(0,nums,currSum, target);
    }
};

*/