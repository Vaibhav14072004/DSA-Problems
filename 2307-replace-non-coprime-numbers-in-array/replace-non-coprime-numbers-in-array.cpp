class Solution {
public:
    inline int lcm(int a, int b) { // a*b = lcm(a,b) * gcd(a,b)
        return 1ll*a*b / __gcd(a,b);
    }
    inline bool coprime(int a, int b){
        return __gcd(a,b) > 1;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret; // will act as a stack
        int n = nums.size();
        for(int i = 0; i < n;++i){
            int cur = nums[i];
            while(ret.size() && coprime(ret.back(), cur)){
                cur = lcm(ret.back(), cur);
                ret.pop_back();
            }
                ret.push_back(cur);
            }
        
        return ret;
    }
};