// Approach 1 -> Using DFS
// TC= O(N*M)

class Solution {
public:
    int DFS(int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        if(i < 0 || i>= n || j< 0 || j>= m || grid[i][j]== 0){
            return 0;
        }

        int fish= grid[i][j];
        grid[i][j]= 0;

        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};
        
        for(int k=0; k<4; k++)
        {
            int newX= i+ dirX[k];
            int newY= j+ dirY[k];
            
            // check id newX, newY are valid..
            if(newX >= 0 && newX < n && newY >= 0 && newY < m)
            {
                fish+= DFS(newX,newY,grid,n,m);
            }
        }
    return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int maxi= 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] > 0)
                {
                    maxi= max(maxi, DFS(i,j,grid,n,m));
                }
            }
        }
       return maxi; 
    }
};