// Aproach 2.2 ->> Using Deque (Doubly ended queue)
// TC= O(N*M)

class Solution{
public: 
     int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();

        vector<vector<int>> minDist(n, vector<int> (m, INT_MAX));
        minDist[0][0]= 0;

        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};

        // {dist, {x,y}}
        deque<pair<int, pair<int,int>>> dq;
        dq.push_front({0,{0,0}});

        while(!dq.empty())
        {
            int dist= dq.front().first;
            int x= dq.front().second.first;
            int y= dq.front().second.second;
            dq.pop_front();

            for(int k=0; k<4; k++)
            {
                int newX= x+ dirX[k];
                int newY= y+ dirY[k];

                if(newX < 0 || newY < 0|| newX >= n || newY >= m)
                {
                    continue;
                }

                int wt= grid[newX][newY];

                if(dist+  wt < minDist[newX][newY])
                {
                    minDist[newX][newY]= dist+wt;

                    // rather than pushing directly into deque...
                    // dq.push_front() the pairs having edge as 0
                    if(wt== 0)
                    {
                        dq.push_front({dist+wt ,{newX,newY}});
                    }

                    // dq.push_back() the pairs having edge as 1
                    else
                    {
                        dq.push_back({dist+wt ,{newX,newY}});
                    }
                }
            }
        }
       return minDist[n-1][m-1];    
     }
};







//   ------ TLE ------- (52/54 passes)
// Approach 2.1 ->> Using BFS
// TC= O(N*M)

/*
class Solution{
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();

        vector<vector<int>> minDist(n, vector<int> (m, INT_MAX));
        minDist[0][0]= 0;

        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};
        
        // {dist, {x,y}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{0,0}});
        
        while(!q.empty())
        {
            int dist= q.front().first;
            int x= q.front().second.first;
            int y= q.front().second.second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int newX= x + dirX[k];
                int newY= y+ dirY[k];

                if(newX < 0|| newY < 0 || newX >= n || newY >= m)
                {
                    continue;
                }

                int wt= 0;
                if(grid[newX][newY]== 1){
                    wt= 1;
                }

                if(dist + wt < minDist[newX][newY])
                {
                    minDist[newX][newY]= dist+wt;
                    q.push({dist+wt, {newX, newY}});
                }
            }
        }
        return minDist[n-1][m-1];
    }
};

*/








// Approach 1 ->> 2D Dijsktra
// TC= O(E* log V) where E-> No of edges, V-> Vertices
 
/*

class Solution {
public:
#define P pair<int, pair<int, int>>

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // min heap to store ->> {wt, {x,y}}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> minDist(n, vector<int>(m, INT_MAX));
        minDist[0][0] = 0;

        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        while (!pq.empty()) {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x== n-1 && y== m-1)
            {
                return dist;
            }

            for (int k = 0; k < 4; k++) {
                int newX = x + dirX[k];
                int newY = y + dirY[k];

                if (newX < 0 || newY < 0 || newX >= n || newY >= m){
                    continue;
                }

                int wt = 0;
                if(grid[newX][newY] == 1){
                    wt = 1;
                }

                if (dist + wt < minDist[newX][newY])
                {
                    minDist[newX][newY]= dist+ wt;
                    pq.push({dist+wt, {newX,newY}});
                }
            }
        }
        return minDist[n-1][m-1];
    }
};

*/