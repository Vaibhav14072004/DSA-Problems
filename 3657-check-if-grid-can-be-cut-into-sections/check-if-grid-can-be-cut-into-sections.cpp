class Solution {

vector<vector<int>> mergeintr(vector<vector<int>> arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(auto it : arr){
         if(!ans.empty() && ans.back()[1] > it[0]){
            ans.back()[1] = max(ans.back()[1], it[1]);
         }else{
            ans.push_back(it);
         }
    }
    return ans;
}

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for(auto &it : rectangles){
            int x1 = it[0];
            int x2 = it[2];
            int y1 = it[1];
            int y2 = it[3];
            x.push_back({x1, x2});
            y.push_back({y1, y2});
        }

        vector<vector<int>> result1 = mergeintr(x);
        if(result1.size() >= 3)
            return true;
        vector<vector<int>> result2 = mergeintr(y);
        return result2.size() >= 3;
    }
};