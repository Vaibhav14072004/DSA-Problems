// Approach 3 -> One pass Kadane Algorithm
// Find max out of [maxSubarraySum, abs(minSubarraySum)] in one paas only
// TC= O(N)

class Solution{
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int maxSum= INT_MIN;
        int minSum= INT_MAX;
        int currSum_max= 0;
        int currSum_min= 0;

        for(int i=0; i<n; i++)
        {
            if(currSum_max < 0)
            {
                currSum_max= 0;
            }
            currSum_max+= nums[i];
            maxSum= max(maxSum, currSum_max);

            if(currSum_min > 0)
            {
                currSum_min= 0;
            }
            currSum_min+= nums[i];
            minSum= min(minSum, currSum_min);
        }
    return max(maxSum, abs(minSum));
    }
};





// Approach 2 ->> Kadane Algorithm
// Find max out of [maxSubarraySum, abs(minSubarraySum)]
// TC= O(2*N)

/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int maxSum= INT_MIN;
        int minSum= INT_MAX;
        int sum= 0;

        // Calculate max subarray sum...
        for(int i=0; i<n; i++)
        {
            if(sum < 0){
                sum= 0;
            }

            sum+= nums[i];
            maxSum= max(maxSum, abs(sum));
        }

        // Calculate min subarray sum...
        sum= 0;
        for(int i=0; i<n; i++)
        {
            if(sum > 0){
                sum= 0;
            }
            sum+= nums[i];
            minSum= min(minSum,sum);
        }

    return max(maxSum, abs(minSum));
    }
};

*/






//  --------   TLE  ------------
// Approach 1 -> Brute Force Approach ->> Generate all subarrays
// TC= O(N^2)

/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int maxSum= INT_MIN;

        for(int i=0; i<n; i++){
            int sum= 0;
            for(int j=i; j<n; j++)
            {
                sum+= nums[j];
                maxSum= max(maxSum, abs(sum));
            }  
        }
        return maxSum;
    }
};
*/
