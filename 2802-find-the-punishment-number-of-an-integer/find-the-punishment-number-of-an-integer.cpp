class Solution {
public:
    bool checkSq(int i,int currSum,string s,int num){
        if(i==s.length()) return num==currSum;
        if(currSum>num) return false;
        bool possible=false;
        for(int j=i;j<s.length();j++){
            string sub=s.substr(i,j-i+1);
            int val=stoi(sub);
            possible=possible || checkSq(j+1,currSum+val,s,num);
            if(possible) return true;
        }
        return possible;
    }
    int punishmentNumber(int n) {
        int punish=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;
            string s=to_string(sq);
            if(checkSq(0,0,s,num)){
                punish+=sq;
            }
        }
        return punish;
    }
};