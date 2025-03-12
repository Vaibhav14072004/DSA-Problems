// Approach 2 -> BFS
// TC= O(N*M)

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] > 0)
                {
                    int sum = 0;
                    queue<pair<int, int>> pq;
                    pq.push({i, j});

                    while(!pq.empty())
                    {
                        int row = pq.front().first;
                        int col = pq.front().second;
                        sum+= grid[row][col];
                        grid[row][col] = 0;
                        pq.pop();

                        for (int k = 0; k < 4; k++) 
                        {
                            int newX = row + dirX[k];
                            int newY = col + dirY[k];
                            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] > 0) {
                                pq.push({newX, newY});
                            }
                        }
                    }

                    maxi= max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};






// Approach 1 -> Using DFS
// TC= O(N*M)

/*

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
            if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
grid[newX][newY] > 0)
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

*/