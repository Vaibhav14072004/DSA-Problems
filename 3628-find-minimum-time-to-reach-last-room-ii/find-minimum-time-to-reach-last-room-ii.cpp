class compare{
    public:
    bool operator()(const pair<pair<int,int>,pair<int,int>>&a,const pair<pair<int,int>,pair<int,int>>&b){
        return a.first.first > b.first.first;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
           int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue< pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>> ,compare > pq;
         
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        pq.push({{0,0},{0,0}});
        int time = 0;
        vector<vector<int>> timer(n,vector<int>(m,INT_MAX));
        timer[0][0] = 0;
        int t = 1;
      
        while(!pq.empty()){
           
                auto f = pq.top();
                pq.pop();
                int v = f.first.first;
                int cnt = f.first.second;
                int x = f.second.first;
                int y = f.second.second;
                if (x == n - 1 && y == m - 1)
                    return  v;
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                        int nextTime = max(v, moveTime[nx][ny]) + 1 + (cnt); // Wait if necessary

                        // update if this path having quicker time
                        if (nextTime < timer[nx][ny]) {
                            timer[nx][ny] = nextTime;
                            pq.push({{nextTime,!cnt}, {nx, ny}});
                        }           
                    }
                }
           
            // if(cnt){
            //     t++;
            // } else t--;
            // cnt = !cnt;
        }
        return -1;
    } 
};