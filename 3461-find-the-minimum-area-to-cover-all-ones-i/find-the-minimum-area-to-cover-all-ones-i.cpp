class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        int firstRow= n, lastRow= 0;
        int firstCol= m, lastCol= 0;
        for(int i=0; i<n; i++)
        {
           for(int j=0; j<m; j++)
           {
              if(grid[i][j]== 1)
              {
                  firstRow= min(firstRow,i);
                  firstCol= min(firstCol,j);
                  lastRow= max(lastRow,i);
                  lastCol= max(lastCol, j);
              }
           }
        }
        return (lastCol-firstCol+1)* (lastRow-firstRow+1);
    }
};