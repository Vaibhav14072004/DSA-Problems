class Solution {
public:
int mod=1e9+7;
    long long pow(long long base, long long exponent) {
        long long res = 1;

        
        while (exponent > 0) {
            
            if (exponent % 2 == 1) {
                res = ((res * base) % mod);
            }
            base = (base * base) % mod;
            exponent /= 2;
        
    }
    return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=2;j*j<=num;j++){
                if(num%j==0){
                    vec[i]++;
                    while(num%j==0)num/=j;
                }
            }
            if(num>=2)vec[i]++;
        }
        vector<int>next(n,n);
        vector<int>prev(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&vec[st.top()]<vec[i]){
                int ti=st.top();
                st.pop();
                next[ti]=i;
            }
            if(!st.empty()){
                int pi=st.top();
                prev[i]=pi;
                
            }
            st.push(i);
        }
        vector<long long>sub(n);
        for(int i=0;i<n;i++){
            sub[i]=(long long)(i-prev[i])*(next[i]-i);
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long score=1;
        while(k>0){
            auto [x,y]=pq.top();
            pq.pop();
            long long op=min((long long) k,sub[y]);
            score=(score*pow(x,op))%mod;
            k-=op;
        }
        return score;
    }
};