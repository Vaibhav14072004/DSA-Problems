// Approach 1 -> Backtracking
// TC= O(2^N)

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