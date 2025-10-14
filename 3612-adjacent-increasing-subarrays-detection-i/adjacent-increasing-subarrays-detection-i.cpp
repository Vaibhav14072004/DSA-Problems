
class Solution {
public:
   bool solve(int i, vector<int> &nums, int k)
   {
       int n= nums.size();
       // if(i+k > n)
       // {
       //     return false;
       // }

       for(int j=i+1; j<i+k; j++)
           {
               if(nums[j-1] >= nums[j])
               {
                   return false;
               }
           }
       return true;
   }


    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if (n <= 1)
            return false;

        if(n < 2*k)
        {
            return false;
        }


        for(int i=0;i<= n-k; i++)
        {
             if(solve(i,nums,k))
             {
                if(i+k <= n-k && solve(i+k,nums,k))
                {
                    return true;
                }
             }
        }
        
    return false;
    }
};

