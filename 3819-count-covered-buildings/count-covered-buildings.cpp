class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
    {
        unordered_map<int, vector<int>> row, col;
        
        for(auto &b : buildings)
        {
            row[b[0]].push_back(b[1]);
            col[b[1]].push_back(b[0]);
        }
        
        // Sort all row and column lists
        for(auto &[r, v] : row) sort(v.begin(), v.end());
        for(auto &[c, v] : col) sort(v.begin(), v.end());
        
        int cnt = 0;
        for(auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            
            // check left (y-1), right (y+1) in row[x]
            auto it = lower_bound(row[x].begin(), row[x].end(), y);
            bool hasLeft = (it != row[x].begin());
            bool hasRight = (it != row[x].end() && next(it) != row[x].end());
            
            // check up (x-1), down (x+1) in col[y]
            it = lower_bound(col[y].begin(), col[y].end(), x);
            bool hasUp = (it != col[y].begin());
            bool hasDown = (it != col[y].end() && next(it) != col[y].end());
            
            if(hasLeft && hasRight && hasUp && hasDown)
                cnt++;
        }
        
        return cnt;
    }
};






/*   TLE

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        set<pair<int, int>> st;
        int cnt = 0;

        for (auto it : buildings) {
            st.insert({it[0], it[1]});
        }

        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        for (auto it : buildings)
            {
            int r = it[0];
            int c = it[1];
            bool up = false, down = false, left = false, right = false;

            // check up..
            for (int row = r - 1; row >= 1; row--)
            {
                if(st.find({row,c}) != st.end())
                {
                    up= true;
                    break;
                }
            }

            if(up== false)
            {
                continue;
            }

            // check down..
            for(int row= r+1; row <= n; row++)
                {
                    if(st.find({row,c}) != st.end())
                    {
                        down= true;
                        break;
                    }
                }

            if(down== false)
            {
                continue;
            }

         // check left...
            for(int col= c-1; col >=1; col--)
                {
                    if(st.find({r,col}) != st.end())
                    {
                        left= true;
                        break;
                    }
                }

            if(left== false)
            {
                continue;
            }

            // check right...
            for(int col= c+1; col <=n; col++)
                {
                    if(st.find({r,col}) != st.end())
                    {
                        right= true;
                        break;
                    }
                }

                if(left && right && up && down)
                {
                    cnt++;
                }
        }
    return cnt;
    }
};

*/