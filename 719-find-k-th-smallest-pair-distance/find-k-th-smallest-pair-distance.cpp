// Optimized Approach -> Sliding Window + Binary Search 
// Using Binary Search ... search space would be minDiff to maxDiff

// TC= O(N log N) + O[(2* N)* log N] 

// Overall TC= O(N log N)

class Solution{
public:
    int noOfPairs(vector<int> &nums, int mid)
    {
        int i=0, j= 0, n= nums.size(), cnt= 0;
        while(j < n)
        {
            // shrink the curr window...
            while(i < j && nums[j]-nums[i] > mid)
            {
                i++;
            }
             
         // ex- 1 3 5 then if 5-1-> 4 is less than mid, then obviously 5-3 -> 2 is also less than mid

         // if(nums[j]- nums[i] <= mid) ... no need to write this line...
            cnt+= j-i;
            j++;
        }
      return cnt;  
    }
  

    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n= nums.size();

        sort(nums.begin(), nums.end());  // sort in ascending order..

        // minDiff would be between consecutive pairs..
        int minDiff= INT_MAX;
        for(int i=1; i<n; i++)
        {
            if(minDiff > nums[i]-nums[i-1])
            {
                minDiff= nums[i-1]- nums[i];
            }
        }
        
        // maxDiff would be just diff of maxElement (last element) - minElement (first element)
        int maxDiff= nums[n-1]- nums[0];

        // apply binary search... search space would be minDiff to maxDiff
        int start= minDiff;
        int end= maxDiff;
        int ans;

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            
            // we have to find kth smallest diff... so we need atleast k pairs..
            if(noOfPairs(nums, mid) >= k)
            {
                ans= mid;
                end= mid-1;
            }
            else
            {
                start= mid+1;
            }
        }
    return ans;
    }
};






//    **** Giving TLE *****
//     TC= O(N^2 * log k)

/*
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n= nums.size();

        // to find kth smallest dist -> USe max heap (priority_queue)
        priority_queue<int> pq;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(i != j)
                {
                    pq.push(abs(nums[j]-nums[i]));

                    if(pq.size() > k)
                    {
                        pq.pop();
                    }
                }
            }
        }
    return pq.top();
    }
};

*/