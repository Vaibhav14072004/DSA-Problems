class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int sz = queries.size();
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> questions;
        for (int i = 0; i < sz; i++) questions.push_back({queries[i], i});
        sort(questions.begin(), questions.end());

        vector<int> ans(sz, 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int cnt = 0;
        for (auto &[val, pos]: questions) {
            while (pq.size() > 0 && pq.top().first < val) {
                auto [_, cur] = pq.top();
                auto [x, y] = cur;
                pq.pop();
                cnt += 1;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
            ans[pos] = cnt;
        }
        return ans;
    }
};