// Approach 2 (Kadane Algorithm ) 

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n= arr.size();
       
       int sum= 0;
       int maxi= INT_MIN;

       for(int i=0; i<n; i++)
       {
           sum+= arr[i];
         
        if(sum > maxi)
        {
            maxi= sum;
        }
        
        // if sum is < 0 again initialize sum with 0 in that case...
           if(sum <0)
           {
               sum= 0;
           }
       }
    return maxi;
    }
    };




// Approach 1 (Brute Force) => 204/210 test cases => Giving TLE
// TC= O(n^2)

/*

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n= arr.size();
        int maxi= INT_MIN;

        for(int i=0; i<n; i++)
        {
            int sum= 0;
        // we start loop from i NOT FROM i+1 bcoz 0th index alone can also be our possible ans
            for(int j=i; j<n; j++)
            {
                sum+= arr[j];
                maxi= max(maxi,sum);
            }
        }
        return maxi;
    }
};

*/