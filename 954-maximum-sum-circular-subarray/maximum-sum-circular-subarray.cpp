// Optimal Approach 2 ->  Using global and curr maxima, minima

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n= arr.size();
        
        int globalMax= arr[0], globalMin= arr[0];
        int currMax= arr[0], currMin= arr[0], totalSum= arr[0];

        for(int i=1; i<n; i++)
        {
            currMax= max(currMax+ arr[i], arr[i]);
            currMin= min(currMin+ arr[i], arr[i]);
            totalSum+= arr[i];

            globalMax= max(globalMax, currMax);
            globalMin= min(globalMin, currMin);
        }
        
        // base case ->> If all elements of array are negative -> return absolute greatest number.
        if(globalMax < 0)
        {
            return globalMax;
        }
     
        // final ans will be max of the above 2 cases...
        return max(globalMax, totalSum- globalMin);
    }
};







// Optimal Approach 1 -> Using Kadane's Algorithm -> Beats 63.78 % 

// In case of circular subarray ->> if some elements on end and some on start together form max Subarray sum
// 1. In that case using kadane algo for finding min subarray sum by inverting the original array..
// Max Subarray Circular Sum= (Total Sum - min subarray sum)

//2. In case if all elements on one side form max Subarray sum... directly find it using kadane algo

// Tc= O(N)

/*

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n= arr.size();
        
        // Case 1. When all elements on one side form max Subarray sum...
        int maxSum= 0;
        int totalSum= 0, currSum= 0;
        for(int i=0; i<n; i++)
        {
            totalSum+= arr[i];
            currSum+= arr[i];
            maxSum= max(maxSum, currSum);

            if(currSum < 0){
              currSum= 0;
            }
        }

        // Case 2. When some elements on end and some on starting form max subarray sum from given circular array.
        // Max circular subarray sum= (Total Sum - min subarray sum)  ->> So find min subarray sum using kadane algo

        int minSum= INT_MAX;
        currSum= 0;
        for(int i=0; i<n; i++)
        {
            currSum+= arr[i];
            minSum= min(currSum, minSum);
           
           // to find min subarray sum using kadane algorithm...
            if(currSum > 0){
                currSum= 0;
            }
        }
        
        int maxCircularSum= totalSum - minSum;

        // Base case ->> If all numbers are negative, maxCircularSum will be zero which is not correct, 
        // we should return the maxSum (which would be the largest single element in this case)
        if (maxSum == 0 && totalSum< 0) {
            return *max_element(arr.begin(),arr.end());
        }
       
       // final ans will be max of the above 2 cases...
       return max(maxSum, maxCircularSum);
    }
};


*/






/* Brute Force Approach 
   TC= O(N^2)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();

        int maxSum= -1e9;
        for(int i=0; i<n; i++)
        {
            int sum= 0;
            for(int j=0; j<n; j++)
            {
                sum+= nums[(i+j) % n];
                maxSum= max(maxSum,sum);
            }
        }
    return maxSum;
    }
};

*/