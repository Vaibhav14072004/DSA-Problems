// Approach -> Backtracking
// TC= O(N*M) + O(4 ^ (No of empty squares))

class Solution {
public:
    int backtracking(int i, int j,vector<vector<int>> &grid,int cnt,int nonobstacles,int n,int m)
    {
        if(i < 0 || i>= n || j < 0 || j>= m) return 0;
        if(grid[i][j]== -1) return 0;

        // if reached dest, check whethewr we have covered all empty squares..
        if(grid[i][j]== 2)
        {
            if(cnt== nonobstacles) return 1;
            return 0;
        }

        vector<int> rowdir= {-1,0,1,0};
        vector<int> coldir= {0,1,0,-1};

        // mark the curr cell as visited
        grid[i][j]= -1;
        
        int ans= 0;
        for(int k=0; k<4; k++)
        {
            int nrow= i+rowdir[k];
            int ncol= j+ coldir[k];
            
            if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)  continue;
            ans+= backtracking(nrow,ncol,grid,cnt+1,nonobstacles,n,m);
        }

      // backtrack...
      grid[i][j]= 0;
      return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
       

        int nonobstacles= 0;
        int startx,starty;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<m; j++)
            {
                if(grid[i][j]== 1)
                {
                    startx= i;
                    starty= j;
                    // start node is also non obstacle
                   nonobstacles++;
                }
                else if(grid[i][j]== 0)
                {
                   nonobstacles++;
                }
            }
        }

        return backtracking(startx,starty,grid,0,nonobstacles,n,m);
    }
};