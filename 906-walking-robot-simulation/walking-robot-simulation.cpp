// Approach -> Using unordered_set
// TC= O(N* K)

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        
        // first insert obstacles in set..
        for(vector<int> &it: obstacles)
        {
            string temp= to_string(it[0]) + '_' + to_string(it[1]);
            st.insert(temp);
        }
        
        // N E S W
        vector<int> dirX= {0,1,0,-1};
        vector<int> dirY= {1,0,-1,0};

        // Initially robot is facing in north direction {0,1}
        int dirIndex= 0;

        int x= 0, y= 0;
        int maxDist= 0;

        for(int i=0; i<commands.size(); i++)
        {
            // 1. Turn in right direction 
            if(commands[i]== -1)
            {
                dirIndex= (dirIndex+1)% 4; 
            }

            // turn in left direction
            else if(commands[i]== -2)
            {
               dirIndex= (dirIndex-1 + 4) % 4;
            }

            // move forward until obstacle NOT found
            else
            {
                for(int j=0; j<commands[i]; j++)
                {
                    int newX= x + dirX[dirIndex];
                    int newY= y + dirY[dirIndex];

                    string curr= to_string(newX) + '_' + to_string(newY);

                    // if there is obstacle, break
                    if(st.find(curr) != st.end())
                    {
                        break;
                    }

                   x= newX;
                   y= newY;
                }

              maxDist= max(maxDist, x*x + y*y);
            }
        }
        return maxDist;
    }
};






/*
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
*/