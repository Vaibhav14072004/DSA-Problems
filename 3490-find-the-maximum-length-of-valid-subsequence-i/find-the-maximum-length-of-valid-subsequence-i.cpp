class Solution {
public:
    int maximumLength(vector<int>& nu) {
        int odd = 0;
        int n = nu.size();
        for (int i : nu)
            odd += (i % 2);

        int o = 0;
        int e = 0;
        for (int i : nu) {
            if (o % 2 != i % 2)
                o++;
            if (e % 2 == i % 2)
                e++;
        }

        int maxi = std::max({e, o, odd, n - odd});
        return maxi;
    }
};