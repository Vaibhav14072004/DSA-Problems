// Approach 2 -> Using 2 Variables (leftSum and rightSum)
// TC= O(N)
// SC= O(1)

class Solution{
public:  
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size();

        long long rightSum= 0;
        for(int i=n-1; i>=0; i--)
        {
            rightSum+= nums[i];
        }

        long long leftSum= 0;
        int cnt= 0;

        for(int i=0; i<n-1; i++)
        {
            leftSum+= nums[i];
            rightSum-= nums[i];

            if(leftSum >= rightSum)
            {
                cnt++;
            }
        }
    return cnt;
    }
};
 





// Approach 2 ->> Using Prefix array + one leftSum variable
// TC= O(N)
// SC= O(N)

/*

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size();

        vector<long long> rightPrefix(n,0);
        rightPrefix[n-1]= nums[n-1];

        for(int i=n-2; i>=0; i--)
        {
           rightPrefix[i]= nums[i] + rightPrefix[i+1];
        }
        
        long long leftSum= 0;
        int cnt= 0; 
        for(int i=0; i<n-1; i++)
        {
            leftSum+= nums[i];
            if(leftSum >= rightPrefix[i+1])
            {
                cnt++;
            }
        }
    return cnt;
    }
};

*/