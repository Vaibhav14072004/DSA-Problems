// BRUTE FORCE Approach ->> Generating all subarrrays...
// TC= O(N^2) + O(N log N)

class Solution {
public:
    #define MOD 1000000007

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySum;

        for(int i=0; i<n; i++)
        {
             int sum= 0;
            for(int j=i; j<n; j++)
            {
               sum= (sum+ nums[j]) % MOD;
                subarraySum.push_back(sum);
            }
        }
        
        sort(subarraySum.begin(), subarraySum.end());

        long long ans= 0;

        // 1 based indexing...
        for(int i= left-1; i< right; i++)
        {
           ans= (ans + subarraySum[i]) % MOD;
        }
    return static_cast<int> (ans);
    }
};
