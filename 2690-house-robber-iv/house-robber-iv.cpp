// Approach 2 ->> Binary Search -> (Minimize the maximum value)
// TC= O[log(maxi-mini)* N]

class Solution{
 public: 
    bool binarySearch(int mid, vector<int> &nums, int k)
    {
        int cnt= 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= mid){
                cnt++;
                i++; // bcoz we cannot pick adjacent values
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n= nums.size();  
        int maxi= INT_MIN;
        int mini= INT_MAX;

        for(int i=0; i<n; i++){
            maxi= max(maxi, nums[i]);
            mini= min(mini, nums[i]);
        }

        // apply bnary Search with range -> (Mini to Maxi)
        int start= mini;
        int end= maxi;
        int ans= -1;

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(binarySearch(mid,nums,k)){
                ans= mid;
                end= mid-1;  // find lowest possible ans
            }
            else{
              start= mid+1;
            }
        }
    return ans;
    }
};






//  ------ TLE  ----------
// Approach 1 -> Using DP (Take, Not Take)
// TC= O(N* k)

/*

class Solution {
public:
    int solve(int idx, int cnt, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n= nums.size();
        if(cnt== 0) return 0; 

        // ivalid path
        if(idx >= n) return INT_MAX;

        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        int take= INT_MIN;
        take= max(nums[idx], solve(idx+2, cnt-1, nums, dp));
        int NOTtake= solve(idx+1, cnt, nums, dp);

        return dp[idx][cnt] = min(take, NOTtake);
    }

    int minCapability(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int> (k+1, -1));
        return solve(0,k,nums,dp);
    }
};

*/