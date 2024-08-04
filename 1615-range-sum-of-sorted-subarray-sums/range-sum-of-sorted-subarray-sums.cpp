// Approach 2.2 -> Optimized using Min Heap(Priority_queue)
// TC= O(N log N) + O(N^2 log N)

// SC= O(N) bcoz At Max n elements will be there in pq 

class Solution{
public:
    #define MOD 1000000007

    int rangeSum(vector<int>& nums, int n, int left, int right){

        // {subarray Sum, END Index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++)
        {
            pq.push({nums[i], i});
        }
        
        int ans= 0;
        for(int i=1; i<= right; i++)
        {
            int currSum= pq.top().first;
            int endIndex= pq.top().second;
            pq.pop();

            if(i >= left)
            {
                ans= (ans+ currSum) % MOD;
            }

            if(endIndex+1 < n)
            {
                pq.push({currSum + nums[endIndex+1], endIndex+1});
            }
        }
      return ans;
    }
};







// Approach 2 -> Using Min heap (Priority_queue)
// TC= O(N* log N) + O[(n*(n+1)/2 * log (n*(n+1)/2)] + O(N)
// TC= O(N* log N) + O[N^2 log N^2] + O(N)

// TC= O(N* log N) + O(N^2 log N) + O(N)

// SC= O(N) ->> At max there would be n elements in priority_queue (One pop operation, one addition)

/*

class Solution{
public:
    #define MOD 1000000007

    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        // {subarray Sum, END Index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> subarraySum;
        for(int i=0; i<n; i++)
        {
            pq.push({nums[i],i});
        }
        
        // this will run for all subarrays... (n* (n+1))/2 
        // all subarrays will be by default arranged in ascending order..
        while(!pq.empty())
        {
            int currSum= pq.top().first;
            int endIndex= pq.top().second;
            pq.pop();
            subarraySum.push_back(currSum);

            if(endIndex+1 < n)
            {
               pq.push({currSum + nums[endIndex+1], endIndex+1});
            }
        }
        
        // 1 based indexing...
        int ans= 0;
        for(int i=left-1; i<right; i++)
        {
            ans= (ans + subarraySum[i]) % MOD;
        }
    return ans;
    }
};








// BRUTE FORCE Approach ->> Generating all subarrrays...
// TC= O(N^2) + O[(n*(n+1)/2 * log (n*(n+1)/2)] + O(N)
// TC= O(N^2) + O[N^2 log N^2] 

// O(N^2) + O(N^2 log N)
// SC= O(N)

/*

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

*/