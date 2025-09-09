#define mod 1000000007
class Solution {
    public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long sum = 0;
        vector<long>frozen(n+forget+1, 0);
        frozen[1] = 1;
        for (int i = delay+1; i <= n; i++) {
            if (i > forget) {
                sum -= frozen[i - forget];
            }
            sum = (sum + mod)%mod;
            if (i > delay)
            sum += frozen[i - delay];
            sum = (sum + mod)%mod;

            frozen[i] = sum;
            // printf("%d\n", sum);
        }
        for (int i = 0; i <= delay-1; i++) {
            // printf("%d %d\n", i, frozen[n - i]);
            sum += frozen[n - i];
            sum = (sum + mod)%mod;

        }
        return sum;
    }
    };