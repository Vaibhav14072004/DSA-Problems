class Solution {
public:
    // Method to compute status based on parity of counts
    int getStatus(int cnt_a, int cnt_b) {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }

    // Method to process a specific pair of characters
    int processPair(const string& s, char a, char b, int k) {
        int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int cnt_a = 0, cnt_b = 0;
        int prev_a = 0, prev_b = 0;
        int left = -1;
        int n = s.size();
        int localMax = INT_MIN;

        for (int right = 0; right < n; ++right) {
            cnt_a += (s[right] == a);
            cnt_b += (s[right] == b);

            while (right - left >= k && cnt_b - prev_b >= 2) {
                int left_status = getStatus(prev_a, prev_b);
                best[left_status] = min(best[left_status], prev_a - prev_b);
                ++left;
                prev_a += (s[left] == a);
                prev_b += (s[left] == b);
            }

            int right_status = getStatus(cnt_a, cnt_b);
            int opposite_status = right_status ^ 0b10;

            if (best[opposite_status] != INT_MAX) {
                localMax = max(localMax, cnt_a - cnt_b - best[opposite_status]);
            }
        }
        return localMax;
    }

    // Main function to iterate over all character pairs
    int maxDifference(string s, int k) {
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;
                ans = max(ans, processPair(s, a, b, k));
            }
        }
        return ans;
    }
};