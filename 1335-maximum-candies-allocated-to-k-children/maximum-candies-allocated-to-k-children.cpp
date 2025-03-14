// Approach 2 -> Using Binary Search
// TC= O(N) + O[log(maxCandy)* N]

class Solution{
public:
   bool binarySearch(vector<int> &candies,int maxCandy, long long k)
   {
       long long cnt= 0;
       for(int i=0; i<candies.size(); i++)
       {
          cnt+= candies[i]/maxCandy;
       }
       return cnt>= k;
   }


   int maximumCandies(vector<int>& candies, long long k) {
        int n= candies.size();

        int maxCandy= 0;
        long long sum= 0;
        for(int i=0; i<n; i++){
            maxCandy= max(maxCandy, candies[i]);
            sum+= candies[i];
        }

        // base case
        if(sum < k){
            return 0;
        }

        int start= 1, end= maxCandy;
        int ans= 0;
        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(binarySearch(candies,mid,k))
            {
                ans= mid;
                start= mid+1;  // we have to maximum candy
            }
            else
            {
                end= mid-1;
            }
        }
    return ans;
   }
};







//  ----- TLE -------
// Approach 1 -> Brute Force Approach
// TC= O(N) + O(N* maxC)

/*

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n= candies.size();

        int maxCandy= 0;
        long long sum= 0;
        for(int i=0; i<n; i++){
            maxCandy= max(maxCandy, candies[i]);
            sum+= candies[i];
        }

        // base case
        if(sum < k){
            return 0;
        }
        
        for(int maxi= maxCandy; maxi >= 1; maxi--)
        {
            long long cnt= 0;
            for(int i=0; i<n; i++)
            {
                cnt+= candies[i]/maxi;
            }
            
            // if we can give candies to all k students
            if(cnt >= k)
            {
                return maxi;
            }
        }
     return 0; 
    }
};

*/