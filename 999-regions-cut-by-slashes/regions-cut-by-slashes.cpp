class Solution {
    int m, n;
    vector < vector<int> > dir = {{0, 1},{1, 0}, {0, -1},{-1, 0}};
    vector< vector<bool> > expandedGrid;
public:
    int regionsBySlashes(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();

        expandedGrid.resize(m * 3, vector<bool>(n * 3, false));
        int i, j, ans = 0, baseRow, baseColumn;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                baseRow = i * 3;
                baseColumn = j * 3;
                if (grid[i][j] == '\\') {
                    expandedGrid[baseRow][baseColumn] = true;
                    expandedGrid[baseRow + 1][baseColumn + 1] = true;
                    expandedGrid[baseRow + 2][baseColumn + 2] = true;

                }
                else if (grid[i][j] == '/') {
                    expandedGrid[baseRow][baseColumn + 2] = true;
                    expandedGrid[baseRow + 1][baseColumn + 1] = true;
                    expandedGrid[baseRow + 2][baseColumn] = true;
                }
            }
        }

        for (i = 0; i < m * 3; ++i) {
            for (j = 0; j < n * 3; ++j) {
                if (!expandedGrid[i][j]) {
                    ++ ans;
                    floodFill(i, j);
                }
            }
        }

        return ans;
    }

    void floodFill(int x, int y) {
        expandedGrid[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if (isValid(newX, newY)) {
                floodFill(newX, newY);
            }
        }
    }

    bool isValid(int x, int y) {
        if (x >= 0 && x < m * 3 && y >= 0 && y < n * 3 && !expandedGrid[x][y]) {
            return true;
        }

        return false;
    }
};