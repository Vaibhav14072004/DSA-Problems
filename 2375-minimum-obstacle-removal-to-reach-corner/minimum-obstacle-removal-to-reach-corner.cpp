// Approach 1 ->> Floyd warshall
// TC= O(E* log V) where E-> No of edges, V-> Vertices
 

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