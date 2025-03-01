// Approach 1 ->
// TC= O(3*N)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> ans;
        for(int i=0; i<n-1; i++)
        {
           if(nums[i]== nums[i+1])
           {
               nums[i]= 2*nums[i];
               nums[i+1]= 0;
           } 
           else
           {
              continue;
           }
        }
        
        int cnt= 0;
        for(int i=0; i<n; i++)
        { 
           if(nums[i] != 0)
           {
              ans.push_back(nums[i]);
           }
           else
           {
              cnt++;
           }
        }

        while(cnt--)
        {
            ans.push_back(0);
        }

    return ans;
    }
};