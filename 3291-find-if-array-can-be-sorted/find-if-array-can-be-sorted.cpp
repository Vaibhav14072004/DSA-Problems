// Approach 1 -> Bubble Sort + Counting no of set bits

// TC= O(N^2)* O(max no of set bits of (A,B))
// TC= O(N^2)* O(31)  ->>> O(N^2)

class Solution {
public:
    bool setBits(int a, int b)
    {
        int setBitsA= 0;
        while(a != 0)
        {
            a= a & (a-1);
            setBitsA++;
        }

        int setBitsB= 0;
        while(b != 0)
        {
            b= b & (b-1);
            setBitsB++;
        }
        return setBitsA== setBitsB;
    }


    bool canSortArray(vector<int>& nums) {
        int n= nums.size();

        for(int i=0; i<n; i++)
        {
            bool flag= false;
            for(int j=0; j< n-i-1; j++)
            {
                if(nums[j] > nums[j+1] )
                {
                    if(setBits(nums[j], nums[j+1]))
                    {
                        swap(nums[j], nums[j+1]);
                        flag= true;
                    }
                    // if i is not sorted but bits are not same, they cannot be swapped
                    else
                    {
                        return false;
                    }
                } 

                // skip the iteration if nums[j] <= nums[j+1]
                else
                {
                    continue;
                }
            }

            // if in curr iteration, nothing got swapped, break
            if(!flag)
              break;
        }
    return true;
    }
};