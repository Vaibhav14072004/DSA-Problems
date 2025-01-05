class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shiftLog(n,0);
        for(int i = 0; i < shifts.size(); i++){
            if(shifts[i][2]==0){
                shiftLog[shifts[i][0]]-=1;
                if(shifts[i][1]+1 < n){
                    shiftLog[shifts[i][1]+1]+=1;
                }
            }else{
                shiftLog[shifts[i][0]]+=1;
                if(shifts[i][1]+1 < n){
                    shiftLog[shifts[i][1]+1]-=1;
                }
            }
        } 
        int prSum = 0;
        for(auto& it:shiftLog){
            prSum += it;
            it = prSum;
        }
        for(int i = 0; i < n; i++){
            shiftLog[i]%=26;
            if(shiftLog[i] < 0) shiftLog[i]+=26;
            s[i] = 'a' + (s[i]-'a'+shiftLog[i])%26;
        }
        return s;
    }
};