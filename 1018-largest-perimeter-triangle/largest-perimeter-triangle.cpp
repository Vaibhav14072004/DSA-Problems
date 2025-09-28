class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n= nums.size();
        if(n< 3) return 0;

        // sort in descending order..
        sort(nums.rbegin(),nums.rend());

        for(int i=0; i<n-2; i++)
        {
            // we do not need to check all 3 pairs bcoz if sum of 2 sides > largest side
            if(nums[i] < nums[i+1]+ nums[i+2])
            {
                return (nums[i]+ nums[i+1]+ nums[i+2]);
            }
        }
      return 0;  
    }
};