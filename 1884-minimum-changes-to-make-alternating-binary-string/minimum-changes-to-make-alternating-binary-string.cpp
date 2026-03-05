class Solution {
public:
    int solve(string str) {
        int n = str.length();
        int ans = 0;

        for(int i = 1; i < n; i++) {
            if(str[i] == str[i-1]) {
                if(str[i-1] == '0') str[i] = '1';
                else str[i] = '0';
                ans++;
            }
        }
        return ans;
    }

    int minOperations(string str) {
        string str2 = str;

        // flip first character
        if(str2[0] == '0') str2[0] = '1';
        else str2[0] = '0';

        return min(solve(str), solve(str2) + 1);
    }
};