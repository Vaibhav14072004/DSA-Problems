class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Step 1: Find the maximum number in nums
        int maxVal = *max_element(nums.begin(), nums.end()) + k + 1;

        // Step 2: Make a count array to store how many times each number appears
        vector<int> count(maxVal + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        // Step 3: Make prefix sum
        // Now count[i] will tell how many numbers are <= i
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i - 1];
        }

        int res = 0; // To store our final answer (maximum frequency)

        // Step 4: Check for every possible number i
        for (int i = 0; i < maxVal; i++) {
            // Range [i - k, i + k] are numbers that can become i
            int right = min(maxVal, i + k);
            int left = max(0, i - k);

            // How many numbers are in this range
            int windowSize = count[right] - (left > 0 ? count[left - 1] : 0);

            // How many numbers are already equal to i
            int freq = count[i] - (i > 0 ? count[i - 1] : 0);

            // We can use operations to change nearby numbers into i
            // But we can only use numOperations maximum
            int canChange = min(numOperations, windowSize - freq);

            // Total frequency we can make for i
            res = max(res, freq + canChange);
        }

        return res;
    }
};
