class Solution {
public:
 int mod = 1e9+7;
 int dp[301][301];
int solve(int x,int i,int n ){

     if(n<0){
        return 0 ;
    }
 
    if(n==0){
       return 1;
    }
     if(pow(i,x)>n){
         return 0 ;
     }
  if(dp[n][i] != -1) return dp[n][i];
   
        int mm =pow(i,x);
        int inc=solve(x,i+1,n-mm);
    
    int exc =solve(x,i+1,n);
   return dp[n][i]= (inc%mod +exc%mod)%mod;

}
    int numberOfWays(int n, int x) {
      memset(dp, -1, sizeof(dp));
        return solve(x,1,n);
        
    }
};