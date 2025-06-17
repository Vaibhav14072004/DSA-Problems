class Solution {
public:
    long long mod = 1e9 + 7;
    long long exponent(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    vector<long long> fact(int n) {
        vector<long long> f(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] * i) % mod;
        }
        return f;
    }
    long long modInverse(long long base) { return exponent(base, mod - 2); }
    long long nCr(int n, int r) {
        vector<long long> fac = fact(n);
        // ncr = n!/r!(n-r)!
        long long ncr = fac[n];
        ncr = (ncr * modInverse(fac[r])) % mod;
        ncr = (ncr * modInverse(fac[n - r])) % mod;
        return ncr;
    }
    int countGoodArrays(int n, int m, int k) {
        n = 1ll * n;
        m = 1ll * m;
        k = 1ll * k;
        // here we have
        long long res = 1;
        // selecting k places out of (n-1) for pairs and taking values from m
        long long sel = (nCr(n - 1, k) * m) % mod;
        // remaining elements = m-1;
        // left places = n-1-k
        long long rem = exponent(m - 1, n - 1 - k);
        res = (res * rem * sel) % mod;
        return res;
    }
};