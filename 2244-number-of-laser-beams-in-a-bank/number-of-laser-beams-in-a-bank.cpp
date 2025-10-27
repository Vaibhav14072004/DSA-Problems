class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0; // Number of devices in the last valid row
        int ans = 0;
        int row = bank.size();
        int col = bank[0].size();

        for (int i = 0; i < row; i++) {
            int cur = 0; // Count devices in current row
            for (int j = 0; j < col; j++) {
                if (bank[i][j] == '1') {
                    cur++;
                }
            }
            if (cur != 0) {        // Valid row
                ans += last * cur; // Add beams formed with previous row
                last = cur;        // Update last
            }
        }
        return ans;
    }
};