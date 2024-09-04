class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0,dir=90,ans=0;
        map<pair<int,int>,bool>mp;
        for(auto x:obstacles)
        {
            mp[{x[0],x[1]}]=1;
        }
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]<0)
            {
                if(commands[i]==-1){
                    if(dir==270)
                        dir=0;
                    else
                        dir+=90;
                }
                else if(commands[i]==-2)
                {
                    if(dir==0)
                        dir=270;
                    else
                        dir-=90;
                }
            }
            else if(commands[i]>0)
            {
                if(dir==90 || dir==270)
                {
                    int newY=1;
                    if(dir==270)
                        newY=-1;
                    while(commands[i]>0)
                    {
                        if(mp[{x,y+newY}]!=1)
                            y=y+newY;
                        else 
                            break;
                        commands[i]--;
                    }
                }
                else if(dir==180 || dir==0)
                {
                    int newX=1;
                    if(dir==0)
                        newX=-1;
                    while(commands[i]>0)
                    {
                        if(mp[{x+newX,y}]!=1)
                            x=x+newX;
                        else 
                            break;
                        commands[i]--;
                    }
                }
                int temp=(x-0)*(x-0) + (y-0)*(y-0);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};