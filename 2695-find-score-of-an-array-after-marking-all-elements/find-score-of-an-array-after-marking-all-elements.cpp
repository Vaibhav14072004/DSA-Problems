class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int start = i;
            while (i + 1 < nums.size() && nums[i + 1] < nums[i]) {
                i++;
            }
            for (int j = i; j >= start; j -= 2) {
                res += nums[j];
            }
        }
        return res;
    }
};