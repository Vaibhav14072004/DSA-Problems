class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string finalStr = "123450";
        string currStr = getFlatString(board);
        using pis = pair<int, string>;
        queue<pis> q;
        set<string> st;
        for(int i = 0; i < currStr.size(); i++) {
            if (currStr[i] == '0') {
                q.push({i, currStr});
                st.insert(currStr);
                break;
            }
        }
        map<int, vector<int>> swpIdx;
        swpIdx[0] = {1, 3};
        swpIdx[1] = {0, 2, 4};
        swpIdx[2] = {1, 5};
        swpIdx[3] = {0, 4};
        swpIdx[4] = {1, 3, 5};
        swpIdx[5] = {2, 4};
        int res = 0;
        while(q.size() > 0) {
            int n = q.size();
            while(n--) {
                auto p = q.front();
                string curr = p.second;
                int idx = p.first;
                // cout<<"Checking "<<curr<<endl;
                q.pop();
                if (curr == finalStr) {
                    return res;
                }
                for(int v: swpIdx[idx]) {
                    string nxt = curr;
                    swap(nxt[idx], nxt[v]);
                    if (st.find(nxt) == st.end()) {
                        q.push({v, nxt});
                        st.insert(nxt);
                    }
                }
            }
            res++;
        }
        return -1;
    }

private: 
    string getFlatString(vector<vector<int>>& board) {
        string res = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                res.push_back('0' + board[i][j]);
            }
        }
        return res;
    }
};