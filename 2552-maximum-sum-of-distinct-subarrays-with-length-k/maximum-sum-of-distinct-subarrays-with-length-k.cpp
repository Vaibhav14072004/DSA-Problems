// Approach 2 -> Sliding Window (Optimized)
// TC= O(2*N)

class Solution{
public: 
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        
        unordered_set<int> st;
        long long maxSum= 0, sum= 0;
        int i=0, j= 0;

        while(j < n)
        {
            // shrink the curr window, until curr element is removes out of set
            while(st.count(nums[j]))
            {
                sum-= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum+= nums[j];
            st.insert(nums[j]);

            if(j-i+1== k)
            {
               maxSum= max(maxSum, sum);
               sum-= nums[i];
               st.erase(nums[i]);
               i++;
            }

            j++;
        }
        return maxSum;
    }
};






// Approach 1 -> Brute Force Approach
//TC= O(N* K)

/*

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        
        // base case
        if(k > n)
        {
            return 0;
        }
        
        long long maxSum= 0;
        for(int i=0; i<=n-k; i++)
        {
            long long sum= 0;
            unordered_set<int> st;
            bool isValid= true;

            for(int j=i; j<i+k; j++)
            {
                // if curr element already present in curr subarray
                if(st.find(nums[j]) != st.end())
                {
                    isValid= false;
                    break;
                }
                else
                {
                   sum+= nums[j];
                   st.insert(nums[j]);
                }
            }

            if(isValid)
            {
                maxSum= max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

*/