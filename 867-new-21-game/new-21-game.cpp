class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0||k-1+maxPts<=n)return 1;

        vector<double> dp(n+1,0);

        dp[0]=1;
        double windowsum=1;
        double ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=windowsum/maxPts;

            if(i<k){
              windowsum+=dp[i];

            }
            else{
                ans+=dp[i];
            }
            int left=i-maxPts;
            if(left>=0 && left<k){
                windowsum-=dp[left];
            }
        }
        return ans;
    }
};