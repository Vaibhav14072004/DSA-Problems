// TC= O(N)

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n= nums.size();
        long long maxAns= LLONG_MIN;

        int maxi= INT_MIN;
        int mini= INT_MAX;
        for(int i=m-1; i<n; i++)
        {
             maxi= max(maxi, nums[i-m+1]);
             mini= min(mini, nums[i-m+1]);

             maxAns= max(maxAns, (long long) (1LL*maxi*nums[i]));
             maxAns= max(maxAns, (long long) (1LL*mini*nums[i]));
        }
    return maxAns;
    }
};





/*

 ----- If we have to handle separately for m= 1 and m=2 --------

    // if m==1, return max value element ^ 2 
        if(m== 1)
        {
           int maxi= 0;
           for(int i=0; i<n; i++)
           {
              maxi= max(maxi, abs(nums[i]));
           }
           return maxi*maxi;
        }

        else if(m== 2)
        {
            int maxi= INT_MIN;
            int negative= INT_MAX;
            int positive= INT_MIN;

                for(int i=0; i<n; i++)
                {
                    if(nums[i] < 0)
                    {
                        if(negative== INT_MAX)
                        {
                            negative= nums[i];
                        }
                        else
                        {
                            maxi= max(maxi, abs(negative)* abs(nums[i])); 
                            
                            if(abs(nums[i]) > abs(negative))
                            {
                                negative= nums[i];
                            }
                        }
                    }
                    
                    // if nums[i] > 0
                    else
                    {
                            if(positive== INT_MIN)
                            {
                            positive= nums[i];
                            }
                            else
                            {
                            maxi= max(maxi, nums[i]*positive);
                            if(nums[i] > positive)
                            {
                                positive= nums[i];
                            }
                            }
                    }
                }
             return maxi;   
        }

*/