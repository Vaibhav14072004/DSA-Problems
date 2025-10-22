class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        map<int, int> prefix;
        for (auto& x : nums) {
            count[x]++;
            prefix[x - k]++;
            prefix[x + k + 1]--;
            prefix[x] += 0;
        }
        int prev = 0, res = 0;
        for (auto& [i, f] : prefix) {
            int curr = f + prev;
            res = max(res, min(curr, count[i] + ops));
            prev = curr;
        }
        return res;
    }
};