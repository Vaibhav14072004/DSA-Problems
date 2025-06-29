class Solution {
public:
    const int MOD= 1000000007;

    int numSubseq(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        vector<int> power(n);
        power[0]= 1;

        for(int i=1; i<n; i++)
        {
            power[i]= (2*power[i-1]) % MOD;
        }

        int i=0,j= n-1;
        int ans= 0;
        while(i<= j)
        {
            if(nums[i]+nums[j] <= target)
            {
                // using direct pow(2,j-i) will give runtime error
                ans= (ans+ power[j-i] % MOD) % MOD;
                i++;
            }
            else
            {
                j--;
            }
        }
      return ans;  
    }
};