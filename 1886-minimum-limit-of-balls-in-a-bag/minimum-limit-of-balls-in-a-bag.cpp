// Approach ->> Binary Search
// TC= O(N* log N)

/*
Breaking into equal components will NOT give correct ans always...
Ex- {7,17} ->> Breaking it in equal components at every step would give WRONG ans ...

(Suppose if we have to break in equal components, we would use {max heap} to get max 
element at top after every iteration)
*/


class Solution {
public:
// func to check how many operations needed to break all elements in max component of mid
   bool isPossible(int mid, vector<int> &nums, int maxOperations)
   {
       int operations= 0;
       for(int i=0; i<nums.size(); i++)
       {
           if(nums[i] > mid)
           {
               // for 24, mid= 4, operations= 24/4 -1
               // for 23  mid= 4, operations= 23/4 
              operations+= nums[i]/mid;
               if(nums[i] % mid == 0)
               {
                   operations--;
               }
           }
       }
       return operations <= maxOperations;
   }


    int minimumSize(vector<int>& nums, int maxOperations) {
        int n= nums.size();
        int ans= -1;
        
        // search space for binarySearch is 1 to maxElement
        int start= 1;
        int end= *max_element(nums.begin(),nums.end());

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(isPossible(mid,nums,maxOperations))
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