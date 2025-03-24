class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int res=0;
        if(meetings[0][0]!=1){
            res+=(meetings[0][0]-1);
        }
        int mx = meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(mx>days){
                break;
            }
            int d = meetings[i][0]-mx-1;
            mx = max(mx,meetings[i][1]);
            if(d>0){
                res+=d;
            }
        }
        res+=(days-mx);
        return res;
    }
};