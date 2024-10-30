/*   ----- INTUITION -----
    Make a LIS array that will give no of increasing subsequence till
    that index starting from zero index.. (starting from 0th index)

    Also make a LDS array that will give no of decreasing sbsequence
    till that index to end .. (starting from end of array)...
    

    [Longest Increasing Subsequence] <<<- Centre Index ->>> [Longest Decreasing subsequence]
*/


// TC= O(N^2)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();

        vector<int> LIS(n,1);
        vector<int> LDS(n,1);

        // first fill Longest Increasing subsequence
        for(int i=0; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i] > nums[j])
                {
                   LIS[i]= max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        // now fill the longest decreasing subsequence starting from end of array
        for(int i= n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i] > nums[j])
                {
                    LDS[i]= max(LDS[i], 1 + LDS[j]);
                }
            }
        }

        // Rem elements -> (n - LIS[i] - LDS[i]) + 1     ->> Find max of all rem elements..
        // +1 added bcoz both LIS[i] and LDS[i] contains curr index i which is subtracted twice

        int ans= n;
        for(int i=0; i<n; i++)
        {
            // Mountain array should have min of 3 elements, so there should be atleast one LIS and one LDS...
            if(LIS[i] > 1 && LDS[i] > 1)
            {
               int rem= n + 1 - LIS[i] - LDS[i];
               ans= min(ans, rem);
            }
        }
    return ans;
    }
};