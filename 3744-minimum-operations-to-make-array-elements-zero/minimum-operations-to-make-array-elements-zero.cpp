class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto querie: queries) {
            long long l = querie[0], r = querie[1];
            long long total_no_of_divisions = 0, current_denominator = 1, current_lowest = l;
            while(current_denominator <= r) {
                current_denominator *= 4;
                total_no_of_divisions += r - current_lowest + 1;
                current_lowest = max(current_denominator, current_lowest);
            }
            ans += (total_no_of_divisions+1)/2;
        }
        return ans;
    }
};