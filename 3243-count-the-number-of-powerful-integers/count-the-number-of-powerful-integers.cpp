class Solution {
    long long dp[20][3];
    bool check(string& s,string& l){
        bool f=1; int n=l.size(); int j=n-s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]<l[j+i]) break;
            else if(s[i]>l[j+i]){f=0; break;}
        }
        return f;
    }
    long long solve(int limit,string& s,string&l,int idx,int tight,int rem){
        if(idx>= rem){
            if(tight==0 ||check(s,l)) return 1; return 0;
        } 
        if(dp[idx][tight] != -1) return dp[idx][tight];
        int ll= tight==1? min(l[idx]-'0',limit):limit;
        long long ans=0;
        for(int i=0;i<=ll;i++){
            ans += solve(limit,s,l,idx+1,tight && (i==l[idx]-'0'),rem);
        }
        return dp[idx][tight]=ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string l= to_string(start-1),r=to_string(finish);
        int n=s.size(),nl=l.size(), nr=r.size(); long long a1=0,a2=0;
        memset(dp,-1,sizeof(dp));
        if(nl-n>=0 ) a1= solve(limit,s,l,0,1,nl-n);
        memset(dp,-1,sizeof(dp));
        if(nr-n>=0 ) a2=solve(limit,s,r,0,1,nr-n);
        return a2-a1;
    }
};