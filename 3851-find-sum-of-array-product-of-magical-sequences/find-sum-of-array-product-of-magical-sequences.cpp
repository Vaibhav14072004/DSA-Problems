class Solution {
public:
    using ll = long long;
    
    // Fast modular exponentiation
    ll mod_pow(ll a, ll b, ll mod) {
        ll res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    
    int magicalSum(int m, int k, vector<int>& nums) {
        const ll MOD = 1000000007LL;
        int n = nums.size();
        
        // Precompute factorials
        vector<ll> fact(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        
        // Precompute inverse factorials using Fermat's Little Theorem
        ll invf_m = mod_pow(fact[m], MOD - 2, MOD);
        vector<ll> invfact(m + 1);
        invfact[m] = invf_m;
        for (int i = m - 1; i >= 0; --i) {
            invfact[i] = invfact[i + 1] * (i + 1) % MOD;
        }
        
        // Precompute powers: nums[i]^c % MOD
        vector<vector<ll>> pows(n, vector<ll>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            pows[i][0] = 1;
            ll val = nums[i] % MOD;
            for (int c = 1; c <= m; ++c) {
                pows[i][c] = pows[i][c - 1] * val % MOD;
            }
        }
        
        // Precompute contributions: nums[i]^c * inv_factorial[c] % MOD
        vector<vector<ll>> contrib(n, vector<ll>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= m; ++c) {
                contrib[i][c] = pows[i][c] * invfact[c] % MOD;
            }
        }
        
        // DP setup with flattened 4D array
        const int MAX_POS = n + 1;
        const int SZ_REM = m + 1;
        const int SZ_CARRY = m + 1;
        const int SZ_BITS = k + 1;
        const int TOTAL_SIZE = MAX_POS * SZ_REM * SZ_CARRY * SZ_BITS;
        vector<ll> dp(TOTAL_SIZE, 0);
        
        // Index calculation helper
        auto get_idx = [&](int pos, int rem, int carry, int bits) -> int {
            return ((pos * SZ_REM + rem) * SZ_CARRY + carry) * SZ_BITS + bits;
        };
        
        // Base case: start with m elements to choose, no carry, no bits set
        dp[get_idx(0, m, 0, 0)] = 1;
        
        // Fill DP table
        for (int pos = 0; pos < n; ++pos) {
            for (int rem = 0; rem <= m; ++rem) {
                for (int carry = 0; carry <= m; ++carry) {
                    for (int bits = 0; bits <= k; ++bits) {
                        int idx = get_idx(pos, rem, carry, bits);
                        ll val = dp[idx];
                        if (val == 0) continue;
                        
                        // Try choosing c copies of nums[pos]
                        for (int c = 0; c <= rem; ++c) {
                            int total = c + carry;
                            int out_bit = total & 1;        // LSB becomes new bit
                            int new_carry = total >> 1;     // Remaining becomes carry
                            int new_bits = bits + out_bit;
                            
                            if (new_bits > k) continue;     // Pruning
                            
                            int new_rem = rem - c;
                            ll contrib_val = val * contrib[pos][c] % MOD;
                            
                            int new_idx = get_idx(pos + 1, new_rem, new_carry, new_bits);
                            dp[new_idx] = (dp[new_idx] + contrib_val) % MOD;
                        }
                    }
                }
            }
        }
        
        // Collect final answer
        ll ans = 0;
        for (int carry = 0; carry <= m; ++carry) {
            for (int bits = 0; bits <= k; ++bits) {
                // Final bit count includes remaining carry bits
                int final_bits = bits + __builtin_popcount(carry);
                if (final_bits == k) {
                    int idx = get_idx(n, 0, carry, bits);
                    ll val = dp[idx];
                    // Convert from EGF back to actual count
                    ans = (ans + val * fact[m] % MOD) % MOD;
                }
            }
        }
        
        return ans;
    }
};