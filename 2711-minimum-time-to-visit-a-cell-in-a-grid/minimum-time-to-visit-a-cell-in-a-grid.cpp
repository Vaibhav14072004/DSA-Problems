class Solution {
public:

    int minimumTime(vector<vector<int>>& grid) {
        if(grid[1][0] > 1 && grid[0][1] > 1){
            return -1;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visit(n,vector<int>(m,INT_MAX));
        visit[0][0] = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int ct = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            if(cx == n - 1 && cy == m - 1){
                return ct;
            }
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int w = 0;
                    if((grid[nx][ny] - ct) % 2 == 0){
                        w = 1;
                    }
                    int nt = max(ct + 1, grid[nx][ny]+w);
                    if(nt < visit[nx][ny]){
                        visit[nx][ny] = nt;
                        pq.push({nt,{nx,ny}});
                    }
                }
            }
        }
        return visit[n-1][m-1];
    }
};