// Approach 2 -> Optimized
/*
 Odd + Even => ODD  && Even + Odd => ODD

 Even cnt will start from 1, as we can add 0 in anything, which is even no 
 Odd cnt will start from 0

 For even prefix sum, add prev odd no of cnts in ans
 For odd prefix sum, add prev even no of cnts in ans
 */

// TC= O(N)

class Solution {
public:
    const int MOD= 1000000007;

    int numOfSubarrays(vector<int>& arr) {
        int n= arr.size();
        int ans= 0;
        
        int odd= 0;
        int even= 1; // 0 is even no
        
        int prefixSum= 0;
        for(int i=0; i<n; i++)
        {
            prefixSum+= arr[i];

            // if prefix sum is ODD, add even cnt in ans
            if(prefixSum % 2== 1)
            {
                ans= (ans + even) % MOD;
                odd++;
            }

            // if prefix sum is EVEN, add Odd cnt in ans
            else
            {
               ans= (ans+ odd)% MOD;
               even++;
            }
        }
    return ans;
    }
};






//  ------   TLE ----------
// Brute Force Approach ->> Generate all subarrays 
// TC= O(N^2)

/*
class Solution {
public:
    const int MOD= 1000000007;

    int numOfSubarrays(vector<int>& arr) {
        int n= arr.size();
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            int sum= 0;
            for(int j=i; j<n; j++)
            {
                sum+= arr[j];
                if(sum % 2== 1)
                {
                    cnt= (cnt+1) % MOD;
                }
            }
        }
      return cnt;  
    }
};
*/