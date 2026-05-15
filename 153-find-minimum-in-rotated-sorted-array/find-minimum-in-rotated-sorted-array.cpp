/*  Approach 1 =>>
First find the sorted half... 
1. If Left Half Sorted ... compare arr[start] with ans .. and eliminate
   left half by moving start= mid+1

2. If Right Half Sorted ... compare arr[mid] with ans... and eliminate
   right half by moving end= mid-1

---- OPTIMIZATION ----
If left half and right half ... both halves are Sorted
No need to appy binary search on that part...
 =>>>>  Directly compare arr[low] with ans...

 if(arr[start] <= arr[mid] ) -> left half
 if(arr[mid] <= arr[high])  -> Right half

 Directly compare... arr[start] <= arr[end] =>> means both right and left half sorted

*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();

        int start= 0;
        int end= n-1;
        int ans= INT_MAX;

        while(start<= end)
        {
            int mid= start+ (end-start)/2;
        
        
    // OPTIMIZATION => Both left, right half is sorted ... then directly compare ans with arr[low]
    if(nums[start] <= nums[end])
    {
        ans= min(ans, nums[start]);
        break;
    }


    // check if left half is Sorted.. compare arr[low] with ans.. and then eliminate left half
        if(nums[start] <= nums[mid])
        {
            ans= min(ans, nums[start]);
            start= mid+1;
        } 

// check if right half is Sorted... compare arr[mid] with ans... and then eliminate this right half
// if(nums[mid] <= nums[end])
        else
        {
         ans= min(ans, nums[mid]);
         end= mid-1;
        }
        }
        return ans;
    }
};