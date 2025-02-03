class Solution {
public:
    int solve(vector<int>& nums) {
        int inc = 1, dec = 1, currInc = 1, currDec = 1;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                currInc++;
                inc = max(inc, currInc);
                currDec = 1;
            } else if (nums[i] > nums[i + 1]) {
                currDec++;
                dec = max(dec, currDec);
                currInc = 1;
            } else {
                currInc = currDec = 1; // Reset if consecutive elements are equal
            }
        }
        return max(inc, dec);
    }
    
    int longestMonotonicSubarray(vector<int>& nums) {
        return solve(nums);
    }
};