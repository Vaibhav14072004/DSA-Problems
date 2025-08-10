class Solution {
public:
    bool f(unordered_map<int,int> &mp1, unordered_map<int,int> &mp2) {
        for (auto x : mp1) {
            if (mp2.find(x.first) == mp2.end()) return false;
            if (mp1[x.first] != mp2[x.first]) return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> mp;
        int temp = n;
        while (temp > 0) {
            mp[temp % 10]++;
            temp /= 10;
        }

        int a = 1;
        while (a < 1000000000) {
            unordered_map<int,int> np;
            int num = a;
            while (num > 0) {
                np[num % 10]++;
                num /= 10;
            }
            if (f(mp, np) && f(np, mp)) return true;
            a <<= 1; // multiply by 2
        }
        return false;
    }
};