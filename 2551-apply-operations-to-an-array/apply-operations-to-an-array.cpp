// Approach 2 -> Without using extra space (Implace substitution)
// TC= O(2*N)
// SC= O(1)

class Solution{
 public: 
   vector<int> applyOperations(vector<int>& nums) {
        int n= nums.size();

        for(int i=0; i<n-1; i++)
        {
            if(nums[i]== nums[i+1])
            {
                nums[i]= 2* nums[i];
                nums[i+1]= 0;
            }
            else
            {
                continue;
            }
        }

        // swapping all zeroes wih non zero elements to take all zeroes to end
        int i=0;  // for zero element
        int j= 0; // for non zero element
        while(j < n)
        {
            if(nums[j] != 0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
          j++;
        }
    return nums;
   }
};







// Approach 1 -> Using extra space 
// TC= O(3*N)
// TC= O(N)

/*
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

*/