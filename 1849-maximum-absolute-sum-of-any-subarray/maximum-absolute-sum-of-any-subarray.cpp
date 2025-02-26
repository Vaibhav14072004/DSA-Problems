// Approach 2 ->> Kadane Algorithm
// Find max out of [maxSubarraySum, abs(minSubarraySum)]
// TC= O(N)

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
