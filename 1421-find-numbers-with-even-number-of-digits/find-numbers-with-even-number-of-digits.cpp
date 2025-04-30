// TC= O(N)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            string temp= to_string(nums[i]);
            if(temp.size() % 2 == 0)
            {
                cnt++;
            }
        }
      return cnt;  
    }
};