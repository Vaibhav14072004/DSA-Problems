class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> prefix;
        unordered_map<char, int> shift{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        prefix[0] = -1;
        int n = s.length(), result = 0, mask = 0;
        for (int i = 0; i < n; i++) {
            if (shift.count(s[i]))
                mask ^= (1 << shift[s[i]]);
            if (prefix.count(mask))
                result = max(result, i - prefix[mask]);
            else
                prefix[mask] = i;
        }
        return result;
    }
};