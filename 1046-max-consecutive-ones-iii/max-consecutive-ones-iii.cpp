// Approach -> sliding Window
// TC= O(N)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int maxi= 0, zeroes= 0;
        int i=0, j=0;
        while(j < n)
        {
            if(nums[j]== 0)
            {
                zeroes++;
            }

            // shrink the window if zeroes > k
            while(i<= j && zeroes > k)
            {
                 if(nums[i]== 0) zeroes--;
                 i++;
            }

            maxi= max(maxi, j-i+1);
            j++;
        }
      return maxi;  
    }
};