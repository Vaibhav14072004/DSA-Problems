class Solution {
public:
    vector<int>queryResults(int limit,vector<vector<int>>& queries) {
        unordered_map<int,int>mpp,color;  
        unordered_set<int>mark; 
        int count=0;
        vector<int>cnt;
        for(int i=0;i<queries.size();i++) {
            int x=queries[i][0],y=queries[i][1];
            if(mpp.find(x)!=mpp.end()){  
                int prev_clr=mpp[x];
                if (prev_clr==y) 
                {  
                    cnt.push_back(count);
                    continue;
                }
                if(--color[prev_clr]==0)count--;
            } 
            else  mark.insert(x);
            mpp[x]=y; 
            if (++color[y]==1) count++;
            cnt.push_back(count);
        }
        return cnt;
    }
};