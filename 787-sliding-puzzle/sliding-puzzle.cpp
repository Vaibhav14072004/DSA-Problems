// TC= O(6!)= O(720)
// SC= O(6!)= O(720)

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
        // if the index of 0 is this, we can swap it with these indexes..
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        string start = "";

        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;
        visited.insert(start);

        string target = "123450";
        int cnt = 0;

        if (start == target){
            return 0;
        }

        queue<string> q;
        q.push(start);

        while (!q.empty())
        {
            int n = q.size();
            cnt++;
            while (n--)
            {
                string curr = q.front();
                q.pop();

                if (curr == target){
                    return cnt;
                }

                // find index of 0 ->> curr.find('0')
                int idx;
                for (int i = 0; i < 6; i++) {
                    if (curr[i] == '0') {
                        idx = i;
                    }
                }

                // now we can replace the 0 with all diff combinations from map
                for (int it : mp[idx])
                {
                    string newStr = curr;
                    swap(newStr[idx], newStr[it]);
                
                    if(newStr== target)
                    {
                        return cnt;
                    }

                    if(!visited.count(newStr))
                    {
                        visited.insert(newStr);
                        q.push(newStr);
                    }
                }
            }
        }
        return -1;
    }
};