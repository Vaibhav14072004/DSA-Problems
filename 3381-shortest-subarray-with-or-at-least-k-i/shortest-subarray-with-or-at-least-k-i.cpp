// Approach 1 -> Brute Force Approach
// TC= O(N^2)

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = n+1;

        for (int i = 0; i < n; i++)
        {
            int currOR = 0;
            for (int j = i; j < n; j++)
            {
                currOR |= nums[j];

                if (currOR >= k)
                {
                    minLen = min(minLen, j - i + 1);
                }
            }
        }

        if(minLen > n) return -1;
        
        return minLen;
    }
};