/*
   **** [DIFFERENCE ARRAY METHOD] ****
    
    Query=  [L, R, val]

    diff[L] += val
    diff[R+1] -= val

    TC= O(N + Q), Instead of again and again iterating array for diff indices, [To prevent TC= O(N*Q)]
    directly do ans[L]+= val and ans[R+1] -= val
    and then find cummulative sum which will give final changes required..  
*/


// Approach 3 -> Binary Search for iterating queries + Diff array technique
// TC= O[log q* (N+ Q)]

class Solution{
public:
   bool diffArray(vector<vector<int>> &queries, vector<int> &nums, int idx)
   {
       int n= nums.size();
       int q= queries.size();
       vector<int> cumulative(n,0);

       for(int i=0; i<=idx; i++)
       {
           int left= queries[i][0];
           int right= queries[i][1];
           int val= queries[i][2];
           
           cumulative[left]+= val;
           if(right+1 < n)
           {
              cumulative[right+1]-= val;
           }
       }
       
       int currSum= 0;
       for(int i=0; i<n; i++)
       {
          currSum+= cumulative[i];

          // if we cannot make elements of arr as 0, return false
          if(nums[i]-currSum > 0)
          {
             return false;
          }
       }
     return true;  
   }


   int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        int cnt= 0;
        
        // base case -> if all array elements are 0 phle se hi..
        bool flag= true;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
            {
                flag= false;
                break;
            }
        }

        if(flag){
            return 0;
        }

        // Now apply binary search for iterating over queries...
        int start= 0;
        int end= q-1;
        int ans= -1;

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(diffArray(queries,nums,mid))
            {
                // ans is mid+1 bcoz we have to return (i+1)
               ans= mid+1;
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





//  ------ TLE ------
// Approach 2 ->> Difference array technique but iterating nums after every iteration
//  TC= O[Q* (Q+N)]

/*

class Solution {
public:
    bool diffArray(vector<int> &nums, vector<vector<int>> &queries, int idx)
    {
        int n= nums.size();
        vector<int> cumulative(n,0);
        
        // apply diff array technique only upto idx
        for(int i=0; i<= idx; i++)
        {
            int left= queries[i][0];
            int right= queries[i][1];
            int val= queries[i][2];

            cumulative[left]+= val;
            if(right+1 < n){
            cumulative[right+1]-= val;
            }
        }

        int currSum= 0;
        for(int i=0; i<n; i++)
        {
            currSum+= cumulative[i];

            // if we cannot make arr[i] equal to 0
            if(nums[i]-currSum > 0)
            {
                return false;
            }
        }
    return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        int cnt= 0;
        
        // base case -> if all array elements are 0 phle se hi
        bool flag= true;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
              flag= false;
              break;
        }

        if(flag){
            return 0;
        }

        for(int i=0; i<q; i++)
        {   
           // apply diff array technique only upto index i, and check whether we get all zeroes
           if(diffArray(nums,queries,i))
           {
              return i+1;
           }
        }
      return -1;  
    }
};

*/






//   ----- TLE -------
// Approach 1 -> Brutre Force Approach
// TC= O[q* (2N)]

/*

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        int cnt= 0;

        for(int i=0; i<q; i++)
        {
            int left= queries[i][0];
            int right= queries[i][1];
            int val= queries[i][2];
            bool flag= true;
            
            for(int j=left; j<= right; j++)
            {
                nums[j]-= val;
                if(nums[j] < 0) nums[j]= 0;
            }

            // now check if all elements of array become 0, return index
            for(auto it: nums)
            {
                if(it!= 0){
                  flag= false;
                  break;
                }  
            }
            
            // if all elements of arr becomes 0, flag will be true
            if(flag)
            {
                return i+1;
            }
        }
    return -1;
    }
};

*/