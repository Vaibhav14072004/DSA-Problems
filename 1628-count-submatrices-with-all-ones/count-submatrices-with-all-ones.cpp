class Solution {
    // reducing the problem down to 1D array problem
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        vector<int> arr(m);
        for(int startRow = 0; startRow < n; startRow++){
            arr = mat[startRow];
            for(int endRow = startRow; endRow < n; endRow++){
                for(int i = 0 ; i < m ; i++) arr[i] = arr[i] & mat[endRow][i];
                int streak = 1;
                for(int i = 0 ; i < m ; i++){
                    if(arr[i]) res += streak++;
                    else streak = 1;
                }
            }
        }
        return res;
    }
};