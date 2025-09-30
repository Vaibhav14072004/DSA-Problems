//Approach 1 -> Brute Force Approach
// TC= O(N^2)

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n= nums.size();
        while(n > 1)
        {
            vector<int> vec;
            for(int i=1; i<n; i++)
            {
                vec.push_back((nums[i]+nums[i-1]) % 10);
            }
            n--;
            nums= vec;
        }
      return nums[0];  
    }
};