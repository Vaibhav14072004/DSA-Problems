// Approach 2 -> Using 2 extra vectors..
// TC= O(3*N)
// SC= O(2*N)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long maxi= 0;

        // base case
        if(n < 3) return 0;

        vector<int> leftMax(n,0);
        for(int i=1; i<n; i++){
           leftMax[i]= max(leftMax[i-1],nums[i-1]);
        }

        vector<int> rightMax(n,0);
        for(int i=n-2; i>=0; i--)
        {
            rightMax[i]= max(rightMax[i+1],nums[i+1]);
        }

        for(int i=0; i<n; i++)
        {
            maxi= max(maxi, (long long) (leftMax[i]-nums[i])* rightMax[i]);
        }
      return maxi;  
    }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^3)

/*

class Solution{
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