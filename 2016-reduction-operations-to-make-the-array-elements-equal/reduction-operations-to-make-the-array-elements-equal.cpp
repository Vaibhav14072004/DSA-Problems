// Approach 1 ->> Using Sorting
// TC= O(N* log N)

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0;

        sort(nums.begin(),nums.end());

        for(int i=n-1; i>0; i--)
        {
            if(nums[i]== nums[i-1]){
                continue;
            }

            // bcoz we have to convert all rightside elements into nums[i-1]
            cnt+= n-i;
        }
    return cnt;
    }
};