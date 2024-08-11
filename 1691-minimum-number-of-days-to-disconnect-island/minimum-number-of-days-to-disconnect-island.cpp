// Brute Force Approach -> DFS
// This problem can be solved optimally using Tarjan Algorithm (algo to check no of bridges)

// TC= O[(M*N)^2] -> in worst case...

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        int n= grid.size();
        int m= grid[0].size();

        // base case
        if(i< 0 || i>= n || j < 0 || j>=m || visited[i][j]== 1 || grid[i][j]== 0)
        {
            return;
        }

        visited[i][j]= 1;
        
        // 1. left
        dfs(i,j-1,visited,grid);

        // 2. right
        dfs(i,j+1,visited,grid);

        // 3. up
        dfs(i-1,j,visited,grid);

        // 4. down
        dfs(i+1,j,visited,grid);
    }


    int noOfIslands(vector<vector<int>> &grid)
    {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));
        
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]== 1)
                {
                // whenever the new dfs call is made, it means we have got a separate island (component)
                    dfs(i,j,visited,grid);
                    cnt++;
                }
            }
        } 
       return cnt; 
    }


    int minDays(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        int islands= noOfIslands(grid);
        
        // we want only single island in ans... so no operation needed if islands are more than 1 or = 0
        if(islands > 1 || islands== 0)
        {
            return 0;
        }
        
        // one by one make every grid[i][j]= 0, and check for no of islands... 
        // either we need max 1 or 2 operation to break 1 single connected island into 2 islands ...
        else
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(grid[i][j]== 1)
                    {
                        grid[i][j]= 0;
                        islands= noOfIslands(grid);

                        if(islands > 1 || islands == 0)
                        {
                            return 1;
                        }
                        
                        // backtrack...
                        grid[i][j]= 1;
                    }
                }
            }
        }

        // if we cannot make more than 1 component or 0 component in 1 operation 
        // we can definately make it 2 operations...
       return 2; 
    }
};