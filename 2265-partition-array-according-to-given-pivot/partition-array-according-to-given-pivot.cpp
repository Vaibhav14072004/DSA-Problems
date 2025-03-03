// Approach 1 ->> Using 2 extra vectors
// TC= O(2*N)
// SC= O(2*N)

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