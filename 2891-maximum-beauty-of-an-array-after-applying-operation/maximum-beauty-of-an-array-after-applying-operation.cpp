class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        while (r < n) {
            while (r < n && nums[r]-nums[l] <= 2*k) r++, res = max(res, r-l);
            l++;
        }
        return res;
    }
};