/*
    i ..... j..... k  ->> (nums[i]-nums[j])* nums[k]
    so we need to maximize nums[i] as well as nums[k]
*/


// Approach 3 -> Optimized Without using extra space (only one iteration)
// TC= O(N)
// SC= O(1)

class Solution{
 public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        if(n < 3) return 0;

        long long result= 0;
        int maxDiff= 0, leftMax= 0; 
        for(int i=0; i<n; i++)
        {
            result= max(result, (long long) maxDiff* nums[i]);
            maxDiff= max(maxDiff, leftMax-nums[i]);
            leftMax= max(leftMax,nums[i]);
        }
      return result;  
    }
};





/*  -------  WRONG ANS  ----------
class Solution{
public:
   long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long maxi= 0;

        if(n < 3) return 0;
        
        int leftMax= nums[0], rightMax= nums[n-1];
        for(int i=1; i<n-1; i++){
            maxi= max(maxi, (long long) (leftMax-nums[i])* rightMax);
            leftMax= max(leftMax, nums[i]);
            rightMax= max(rightMax, nums[i+1]);
        }
    return maxi;    
   }};
*/






// Approach 2 -> Using leftMax array and rightMax array 
// Tc= O(3*N)
// SC= O(2*N)

/*

class Solution{
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long maxi= 0;
        
        // i ..... j..... k  ->> (nums[i]-nums[j])* nums[k]
        // so we need to maximize nums[i] as well as nums[k]

        vector<int> leftMax(n,0);
        for(int i=1; i<n; i++)
        {
           leftMax[i]= max(leftMax[i-1],nums[i-1]);
        }
        
        vector<int> rightMaxK(n,0);
        for(int i=n-2; i>=0; i--)
        {
           rightMaxK[i]= max(rightMaxK[i+1],nums[i+1]);
        }
        
        for(int i=0; i<n; i++)
        {
            maxi= max(maxi, (long long) (leftMax[i]-nums[i])* rightMaxK[i]);
        }
      return maxi;  
    }
};

*/








// Approach 1 -> Brute Force Approach
// TC= O(N^3)
// SC= O(1)

/*

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long maxi= 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    maxi= max(maxi, (long long) (nums[i]-nums[j])* nums[k]);
                }
            }
        }
      return maxi;  
    }
};

*/