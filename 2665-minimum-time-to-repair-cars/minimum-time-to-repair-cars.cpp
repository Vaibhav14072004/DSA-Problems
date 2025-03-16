// Approach ->> Using Binary Search
// (We have to minimize the maximum time)

// TC= O[log(maxRank* cars*cars)* (N)]

class Solution {
public:
    bool binarySearch(vector<int> &ranks, long long mid, int cars)
    {
         int n= ranks.size();
         long long cnt= 0;
         for(int i=0; i<n; i++)
         {
            // cars= sqrt(time/rank);
             cnt+= (long long) sqrt(mid/ranks[i]);
         }
         return cnt >= cars;
    }


    long long repairCars(vector<int>& ranks, int cars) {
        int n= ranks.size();

        // Time taken = [r* n^2] where r is rank, n is no of cars
        int maxRank= *max_element(ranks.begin(),ranks.end());
        
        // Range for binarySearch would be -> 1 to [maxRank* cars^2]
        long long start= 1;
        long long end= 1LL* maxRank*cars*cars;
        long long ans= -1;

        // mid is the total time in which we can finish if all mechanics work simultaneously
        while(start <= end)
        {
            long long mid= start+ (end-start)/2;
            if(binarySearch(ranks,mid,cars))
            {
                ans= mid;
                end= mid-1; // we need min time possible
            }
            else
            {
                start= mid+1;
            }
        }
     return ans;
    }
};