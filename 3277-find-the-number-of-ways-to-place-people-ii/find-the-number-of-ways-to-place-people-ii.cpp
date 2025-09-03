class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
    int n = points.size();
    int res = 0;

    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0] ;
    });

    for(int i = 0; i < n ; i++) {
        int a = points[i][1];
        int last = INT_MIN;
        for(int j = i+1 ; j < n ; j++) {
            int b = points[j][1];
            if(b <= a && last < b) {
                last = b;
                res++;
            }
        }
    }
    return res;
    }
};