class Solution {
public:
    vector<pair<int,int>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int swimInWater(vector<vector<int>>& grid){
        int n = grid.size();
        using T = pair<int,pair<int,int>>; //{elevation, {row, col}}
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({grid[0][0], {0, 0}}); 

        int time = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int ele = it.first, x = it.second.first, y = it.second.second;
            
            grid[x][y] = 1e9; //mark visited
            time = max(time, ele);
            if(x == n-1 && y == n-1) return time;

            for(auto [dx, dy] : dir){
                int nx = x + dx, ny = y + dy;

                if(min(nx, ny) >= 0 && max(nx, ny) < n && grid[nx][ny] != 1e9){
                    pq.push({grid[nx][ny], {nx, ny}});
                } 
            }
        }

        return 0;
    }
};