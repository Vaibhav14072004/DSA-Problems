class Solution {
public:
    int n, m;
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }

        int sum = grid[i][j];
        grid[i][j] = 0;

        sum +=solve(grid, i+1, j);
        sum +=solve(grid, i-1, j);
        sum +=solve(grid, i, j+1);
        sum +=solve(grid, i, j-1);    

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int res = solve(grid, i, j);
                    maxi = max(maxi, res);
                }
            }
        }

        return maxi;
    }
};