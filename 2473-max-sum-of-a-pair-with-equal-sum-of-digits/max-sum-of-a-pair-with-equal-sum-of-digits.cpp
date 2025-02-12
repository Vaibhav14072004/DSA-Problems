class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n=a.size();
        vector<int>sum(n);
        for(int i=0;i<n;i++)
        {
            sum[i]=digitsum(a[i]);
        }
        int ans=-1;
        unordered_map<int,int>hm;
        for(int i=0;i<n;i++)
        {
            if(hm.find(sum[i])!=hm.end())
            {
                ans=max(ans,a[i]+a[hm[sum[i]]]);
               hm[sum[i]]=a[i]>a[hm[sum[i]]] ? i:hm[sum[i]];//here update with max array value index
            }
            else
            hm[sum[i]]=i;
        }
        return ans;
    }
    int digitsum(int n)
    {
        int s=0;
        while(n>0)
        {
            int rem=n%10;
            s+=rem;
            n=n/10;
        }
        return s;
    }
};