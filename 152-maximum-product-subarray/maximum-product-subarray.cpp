// Approach 2 ->> Optmized Approach

/* 
  Even no of -ve => Multiply all
  ODD no of -ve => 1 minimum -ve number have to be left out

 if suffix, prefix < 0 we still not made it 1 directly bcoz it might possible that
 we again get -ve number, making -ve*-ve to be positive value 
 */

// TC= O(N)

class Solution{
 public:   
   int maxProduct(vector<int> &nums)
   {
      int n= nums.size();
      int suffix= 1, prefix= 1;
      int maxi= INT_MIN;

      for(int i=0; i<n; i++)
      {
          if(suffix== 0) suffix= 1;
          if(prefix== 0) prefix= 1;

          prefix*= nums[i];
          suffix*= nums[n-i-1];

          maxi= max(maxi, max(suffix,prefix));
      }  
    return maxi;  
   }
};





// Approach 1 -> Brute Force Approach
// Generating all subarrays..
// TC= O(N^2)

/*

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxi= INT_MIN;

        for(int i=0; i<n; i++)
        {
            int product= 1;
            for(int j=i; j<n; j++)
            {
               product= product* nums[j];
               maxi= max(maxi, product);  
            }
        }
      return maxi;  
    }
};

*/