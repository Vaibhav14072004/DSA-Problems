// Approach 2 -> Sliding Window Approach
// TC= O(8* N)

// Nums can go upto 50
// No of bits needed= [1 + Upper bound[log 2 (50)]]= 7 bits
// Instead of running loop till 32, run only upto 7

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = n+1;
        
        // to store cnt of set bits, Needed whe we have to shrink the 
        // curr window, we need to remove nums[i] from currOR
        vector<int> bits(32,0);

        int i=0, j= 0, currOR= 0;
        while(j < n)
        {
            currOR|= nums[j];
            for(int idx= 0; idx<8; idx++)
            {
                // check if i th bit is set or NOT
                if(nums[j] & (1<< idx))
                {
                    bits[idx]++;
                }
            }

            // shrink the curr window..
            while(i<= j && currOR >= k)
            {
                minLen= min(minLen, j-i+1);
                for(int idx= 0; idx<8; idx++)
                {
                    if(nums[i] & (1<< idx))
                    {
                        bits[idx]--;
                        if(bits[idx]== 0)
                        {
                            currOR-= (1<<idx);
                        }
                    }
                }
                i++;
            }

            j++;
        }

        if(minLen > n) return -1;

        return minLen;
    }
};







// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

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

*/