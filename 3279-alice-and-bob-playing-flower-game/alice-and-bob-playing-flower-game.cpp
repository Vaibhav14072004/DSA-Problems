class Solution {
public:
    long long flowerGame(int n, int m) {
        long long int oddsm = (m / 2) + (m & 1), evensm = m / 2,
            oddsn = (n / 2) + (n & 1), evensn = n / 2;
        return (oddsm * evensn) + (oddsn * evensm);
    }
};