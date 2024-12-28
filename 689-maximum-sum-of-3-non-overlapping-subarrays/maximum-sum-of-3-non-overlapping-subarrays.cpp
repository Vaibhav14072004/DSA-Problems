// Ques of DP + Sliding Window

// TC= O(N) + O(4*N*M)  ->> O(N)
// SC= O(N*M) ->> O(N)

class Solution {
public:
    int dp[20001][4];
   
   // -------- TC= O(N*M) -> O(4*N)  ---------

   long long findSum(int index, vector<int> &nums, vector<long long> &subarraySum, int cnt, int k)
   {
       if(cnt== 0)
       {
          return 0;
       }
       
       // if cnt!= 0, it shows INVALID Case...
       if(index >= subarraySum.size())
       {
          return LLONG_MIN;
       }

       if(dp[index][cnt] != -1)
       {
          return dp[index][cnt];
       }

       long long takeSum= subarraySum[index]+ findSum(index+k, nums, subarraySum, cnt-1, k);
       long long NOTakeSum= 0 + findSum(index+1, nums, subarraySum, cnt, k);

     return dp[index][cnt]= max(takeSum, NOTakeSum);
   }


   // ----------  TC= O(4*N*M)   ----------
   // Bcoz there are 4 possible value of cnt, sumTaken Nottaken has TC= O(1) due to memoization

   void solve(int index, vector<int> &nums, vector<long long> &subarraySum, vector<int> &ans,int cnt, int k)
   {
       if(index >= subarraySum.size() || cnt== 0)
       {
          return;
       }
       
       // **** TC= O(1) due to memoization ****

       long long sum_taken= subarraySum[index]+ findSum(index+k, nums,subarraySum, cnt-1,k);
       long long sum_NotTaken= 0 + findSum(index+1, nums, subarraySum, cnt,k);

       // choose that path, from which sum is maximum, also push its index in ans vector
       // here = included bcoz, in case 2 subarrays have same sum, we would take that haiving lower index
       if(sum_taken >= sum_NotTaken)
       {
           ans.push_back(index);
           solve(index+k, nums, subarraySum, ans, cnt-1, k);
       }

       else
       {
          solve(index+1, nums, subarraySum, ans, cnt, k);
       }
   }


    // ------ TC= O(N) --------

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        
        // initialize dp array with -1
        memset(dp, -1, sizeof(dp));
    
        // to calculate subarray sum of length k, starting from index i
        vector<long long> subarraySum(n-k+1, 0);
        int i=0, j= 0, sum= 0;
        while(j < n)
        {
           sum+= nums[j];
           if(j-i+1== k)
           {
               subarraySum[i]= sum;
               sum-= nums[i];
               i++;
           } 
           j++;
        }

        
        int cnt= 3;
        vector<int> ans;
        
        solve(0,nums,subarraySum,ans,cnt,k);
       return ans; 
    }
};