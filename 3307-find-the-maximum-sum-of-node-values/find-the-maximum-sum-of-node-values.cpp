class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long cnt = 0;
        long long res = 0;
        long long minn = INT_MAX;
        long long maxx = INT_MAX;

        for(long long i : nums)
        {
            long long x = i;
            long long y = i ^ k;

            if(x > y)
            {
                res += x;
                maxx = min(maxx, x);
            }
            else
            {
                res += y;
                ++cnt;
            }

            minn = min(minn, abs(x - y));
        }

        if(cnt & 1)
        {
            res -= minn;
        }

        return res;
    }
};