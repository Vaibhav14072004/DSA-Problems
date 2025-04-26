// TC= O(N)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n= nums.size();
        long long ans= 0;

        int minIdx= -1, maxIdx= -1, badIdx= -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > maxK || nums[i] < minK)
            {
                badIdx= i;
            }

            if(nums[i]== maxK) maxIdx= i;
            if(nums[i]== minK) minIdx= i;

            int mini= min(maxIdx,minIdx);
            if(mini-badIdx > 0)
            {
                ans+= mini-badIdx;
            }
        }
      return ans;  
    }
};