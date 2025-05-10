class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1 = 0, z2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int num : nums1) {
            sum1 += num;
            if (num == 0) z1++;
        }

        for (int num : nums2) {
            sum2 += num;
            if (num == 0) z2++;
        }

        if ((z1 == 0 && sum1 < sum2 + z2) || (z2 == 0 && sum2 < sum1 + z1)) {
            return -1;
        }

        return max(sum1 + z1, sum2 + z2);
    }
};