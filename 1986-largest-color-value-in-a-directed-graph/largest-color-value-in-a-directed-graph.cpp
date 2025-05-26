class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n= colors.size();
        vector<vector<int>> adj(n);

        vector<int> indegree(n,0);
        queue<int> q;
        
        // t[1][a] means how many 'a' color nodes we have seen till 1 th node
        vector<vector<int>> t(n,vector<int> (26,0));

        int answer= 0;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0; i<n; i++)
        {
            if(indegree[i]== 0)
            {
                q.push(i);
                t[i][colors[i]-'a']= 1;
            }
        }

        int ans= -1;
        int cntNodes= 0;
        while(!q.empty())
        {
            int u= q.front();
            q.pop();
            cntNodes++;
            answer= max(answer,t[u][colors[u]-'a']);

            // now check its neighbours..
            for(int& v: adj[u])
            {
                // check for all 26 colors
                for(int i=0; i<26; i++)
                {
                    t[v][i]= max(t[v][i], t[u][i]+ (colors[v]-'a' == i));
                }

                indegree[v]--;
                if(indegree[v]== 0)
                {
                    q.push(v);
                }
            }
        }

        // if cycle is present..
        if(cntNodes < n)
        {
            return -1;
        }
        return answer;
    }
};