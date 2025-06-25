class Solution {
public:
    long long countLessEqual(const vector<int>& A, const vector<int>& B, long long x) {
        long long count = 0;
        int m = B.size();

        for (int a : A) {
            if (a > 0) {
                // Count j such that a * B[j] <= x -> B[j] <= x / a
                int l = 0, r = m - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += (pos + 1);
            } else if (a < 0) {
                // Count j such that a * B[j] <= x -> B[j] >= ceil(x / a)
                int l = 0, r = m - 1, pos = m;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += (m - pos);
            } else { // a == 0
                if (x >= 0) count += m;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        long long left = -1e10, right = 1e10, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long cnt = countLessEqual(nums1, nums2, mid);
            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};