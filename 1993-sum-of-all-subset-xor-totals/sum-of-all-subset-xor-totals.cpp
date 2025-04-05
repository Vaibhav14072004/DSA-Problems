class Solution {
public:
    void solve(vector<int>& nums, int curr, int& ans, int i){
        if(i == nums.size()){
            ans += curr;
            return;
        }
        solve(nums, curr, ans, i+1);
        solve(nums, curr^nums[i], ans, i+1);
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curr = 0;
        int ans = 0;
        solve(nums, curr, ans, 0);
        return ans;
    }
};
