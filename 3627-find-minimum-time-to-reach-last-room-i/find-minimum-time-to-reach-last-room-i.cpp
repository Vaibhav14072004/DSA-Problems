class Solution 
{
public:
    vector<int>dx={1,0,-1,0};
    vector<int>dy={0,1,0,-1};
    bool check(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }
    int minTimeToReach(vector<vector<int>>& nums) 
    {
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        set<pair<int,pair<int,int>>>s;
        s.insert({0,{0,0}});
        while(!s.empty())
        {
            auto x=*(s.begin());
            int i=x.second.first;
            int j=x.second.second;
            int w=x.first;
            s.erase(x);
            for(int k=0;k<4;k++)
            {
                if(check(i+dx[k],j+dy[k],n,m))
                {
                    int total;
                    if(w>=nums[i+dx[k]][j+dy[k]])
                        total=w+1;
                    else
                        total=nums[i+dx[k]][j+dy[k]]+1;
                    if(total<dis[i+dx[k]][j+dy[k]])
                    {
                        s.erase({dis[i+dx[k]][j+dy[k]],{i+dx[k],j+dy[k]}});
                        dis[i+dx[k]][j+dy[k]]=total;
                        s.insert({dis[i+dx[k]][j+dy[k]],{i+dx[k],j+dy[k]}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};