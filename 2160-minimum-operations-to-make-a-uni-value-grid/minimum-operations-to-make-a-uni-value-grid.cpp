class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if((v[i]-v[i-1])%x!=0) return -1;
        }
        int sz=v.size();
        if(sz&1){
            int m=v[sz/2];
            int c=0;
            for(auto i:v){
                c+=abs(i-m)/x;
            }
            return c;
        }
        else{
            int m1=v[(sz-1)/2];
            int m2=v[sz/2];
            int c1=0,c2=0;
            for(auto i:v){
                c1+=abs(i-m1)/x;
            }
            for(auto i:v){
                c2+=abs(i-m2)/x;
            }
            return min(c1,c2);
        }
    }
};