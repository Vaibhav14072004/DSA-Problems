/*
   **** [DIFFERENCE ARRAY METHOD] ****
    
    Query=  [L, R, val]

    diff[L] += val
    diff[R+1] -= val

    TC= O(N + Q), Instead of again and again iterating array for diff indices, [To prevent TC= O(N*Q)]
    directly do ans[L]+= val and ans[R+1] -= val
    and then find cummulative sum which will give final changes required..  
*/


// Approach 1 -> Using Diff array technique
// TC= O(q+N)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();

        // base case ->> If all elements of arr is 0 phle se hi..
        bool flag= true;
        for(int i: nums){
            if(i != 0){
              flag= false;
              break;
            }
        }

        if(flag) return true;
        
        vector<int> cumulative(n,0);
        for(int i=0; i<q; i++)
        {
            int left= queries[i][0];
            int right= queries[i][1];
            cumulative[left]+= 1;
            if(right+1 < n)
            {
               cumulative[right+1]-= 1;
            }
        } 
        
        int curr= 0;
        for(int i=0; i<n; i++)
        {
            curr+= cumulative[i];
            nums[i]-= curr;

            // if we cannot make element of nums as 0, return false
            if(nums[i] > 0)
            {
                return false;
            }
            else if(nums[i] < 0)
            {
                nums[i]= 0;
            }
        }
       return true; 
    }
};