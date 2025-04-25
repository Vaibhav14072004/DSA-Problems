// Approach -> Using Tabulation
// TC= O(N^2)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        int maxLen= 0;
        for(int i=0; i<n; i++)
        {
            for(int prev= 0; prev < i; prev++)
            {
                if(nums[i] > nums[prev] && dp[i] < 1+ dp[prev])
                {
                    dp[i]= 1+ dp[prev];
                    cnt[i]= cnt[prev];
                }

                // if dp[i]== 1 + dp[prev] means there are multiple ways ..
                else if(nums[i] > nums[prev] && dp[i]== 1+ dp[prev])
                {
                    dp[i]= 1+ dp[prev];
                    cnt[i]+= cnt[prev];
                }
            }

            maxLen= max(maxLen, dp[i]);
        }

        int ans= 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]== maxLen)
            {
                ans+= cnt[i];
            }
        }
    return ans;
    }
};