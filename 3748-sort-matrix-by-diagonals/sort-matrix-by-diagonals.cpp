// Using ordered map, so TC for map operation will be log(N+M)
// bcoz there will M+N keys in map
// TC= O(N*M* log(N+M))


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        map<int,vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
              mp[i-j].push_back(grid[i][j]);
            }
        }
        
        vector<vector<int>> ans;
        for(auto &it: mp)
        {
            if(it.first < 0)
            {
               sort(it.second.rbegin(),it.second.rend());
            }
            else
            {
                sort(it.second.begin(),it.second.end());
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                grid[i][j]= mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
    return grid;
    }
};