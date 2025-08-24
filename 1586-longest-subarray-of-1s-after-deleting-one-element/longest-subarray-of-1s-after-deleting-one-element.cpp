// TC= O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        
        int maxi= 0, curr= 0, prev= -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]== 1)
            {
                curr++;
            }
            else
            {
               if(prev== -1) maxi= max(maxi, curr);
               else maxi= max(maxi, curr+prev);

               prev= curr;
               curr= 0;
            }
        }

        // handle maxi after loop ends
        if(prev== -1) maxi= max(maxi, curr);
        else maxi= max(maxi, curr+prev);

      return maxi== n ? maxi-1 : maxi;
    }
};