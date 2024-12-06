class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>b(banned.begin(),banned.end());
        int mc=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(b.count(i)==0){
                sum +=i;
                if(sum>maxSum) break;
                mc++;
            }
        }
        return mc;
    }
};