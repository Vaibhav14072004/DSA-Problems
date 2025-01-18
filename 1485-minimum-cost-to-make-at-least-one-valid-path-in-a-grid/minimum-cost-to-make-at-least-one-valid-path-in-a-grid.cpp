class Solution {
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty())
        {
            int topRow = pq.top().second.first;
            int topCol = pq.top().second.second;
            int count = pq.top().first;

            pq.pop();

            if (topRow == n-1 and topCol == m-1)   return count;

            if (vis[topRow][topCol])   continue;
            vis[topRow][topCol] = true;

            int dir = grid[topRow][topCol];
            int dirRow = 0 , dirCol = 0;

            if (dir == 1) 
            {
                dirRow = topRow ;
                dirCol = topCol + 1;
            } 
            else if (dir == 2)
            {
                dirRow = topRow;
                dirCol = topCol - 1;
            } 
            else if (dir == 3)
            {
                dirRow = topRow + 1;
                dirCol = topCol;
            }
            else
            {
                dirRow = topRow - 1;
                dirCol = topCol;
            }


            for (int i=0;i<4;i++)
            {
                int newRow = topRow + dx[i];
                int newCol = topCol + dy[i];

                if (newRow >= 0 and newRow < n and newCol >= 0 and 
                    newCol < m and vis[newRow][newCol] == false)
                {
                    if (newRow == dirRow and newCol == dirCol)
                    {
                        pq.push({count, {newRow, newCol}});
                    } 
                    else   
                    {
                        pq.push({count+1, {newRow, newCol}});
                    }  

                }
            }

        }
        
        return -1;
    }
};





//  -------- TLE ---------
// Approach 1 -> Backtracking
// TC= O[4^ (N*M)]

/*

class Solution {
public:
    int DFS(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited,int cost,int n,int m)
    {
        // if destination reached...
        if(i== n-1 && j== m-1)
        {
            return cost;
        }
         
        visited[i][j]= true;

        // {Up, Right, Down, Left}
        // vector<int> dirX= {-1,0,1,0};
        // vector<int> dirY= {0,1,0,-1};
        
        // {Right, Left, Down, Up}
        vector<vector<int>> dir= {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int minCost= INT_MAX;
        for(int k=0; k<4; k++)
        {
            int newX= i+ dir[k][0];
            int newY= j+ dir[k][1];

            if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY])
            {
                int newCost= cost;
               if((grid[i][j]-1 != k)){
                 newCost+= 1;
                }

              minCost= min(minCost, DFS(newX,newY,grid,visited,newCost,n,m));
            }
        }
         
        // backtracking..
        visited[i][j]= false;

        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<bool>> visited(n, vector<bool> (m,false));
        int cost= 0;
        return DFS(0,0,grid,visited,cost,n,m);
    }
};

*/