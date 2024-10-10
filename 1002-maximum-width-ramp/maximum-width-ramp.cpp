// Approach 2 -> Considering track of max and min element till now..
// TC= O(2*N)
// SC= O(2*N)

class Solution{
public:
  int maxWidthRamp(vector<int>& nums) {
        int n= nums.size();
        vector<int> maximum(n);
        vector<int> minimum(n);
        
        // storing the minimum element obtained till now..
        minimum[0]= nums[0];
        for(int i=1; i<n; i++)
        {
            minimum[i]= min(minimum[i-1], nums[i]);
        }
        
        // storing the maximum element obtained till now..
        maximum[n-1]= nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            maximum[i]= max(maximum[i+1], nums[i]);
        }

        int i=0, j=1;
        int maxi= 0;

        while(i < n && j < n)
        {
            if(minimum[i] <= maximum[j])
            {
                 maxi= max(maxi, j-i);
                 j++;
            }
            else
            {
                i++;
            }
        }
    return maxi;
    }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n= nums.size();
        
        int maxi= INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i] <= nums[j]){
                   maxi= max(maxi, j-i);
                }
            }
        }
        return maxi;
    }
};

*/