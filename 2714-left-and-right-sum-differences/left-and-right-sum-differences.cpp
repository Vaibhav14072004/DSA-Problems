class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n= nums.size();
        int lsum=0;
        vector<int>rsum(n,0);
        rsum[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rsum[i]=rsum[i+1]+nums[i];
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            lsum+= nums[i];
            ans[i]= abs(lsum-rsum[i]);
        }
        return ans;
    }
};