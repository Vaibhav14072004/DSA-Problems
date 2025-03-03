// Approach 2 -> Without using extra space
// TC= O(2*N)
// SC= O(1)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        vector<int> ans(n,pivot);
        
        // first only push elements in ans vector that are less than pivot
        int idx= 0;
        for(int i=0; i<n; i++)
        {
           if(nums[i] < pivot)
           {
               ans[idx]= nums[i];
               idx++;
           }
        }

        // now push elements in ans vector from end that are greater than pivot
        idx= n-1;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] > pivot)
            {
                ans[idx]= nums[i];
                idx--;
            }
        }
      return ans;  
    }
};







// Approach 1 ->> Using 2 extra vectors
// TC= O(2*N)
// SC= O(2*N)

/*

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        vector<int> ans;
        vector<int> less;
        vector<int> greater;
        
        int equal= 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < pivot)
            {
               less.push_back(nums[i]);
            }
            else if(nums[i] > pivot)
            {
                greater.push_back(nums[i]);
            }
            else
            {
                equal++;
            }
        }

        for(int i=0; i<less.size(); i++)
        {
            ans.push_back(less[i]);
        }

        while(equal--)
        {
            ans.push_back(pivot);
        }

        for(int i=0; i<greater.size(); i++)
        {
            ans.push_back(greater[i]);
        }
      return ans;  
    }
};

*/