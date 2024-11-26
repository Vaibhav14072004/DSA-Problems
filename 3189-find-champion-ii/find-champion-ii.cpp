// TC= O(N)

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m= edges.size();
        vector<int> indegree(n,0);

        for(int i=0; i<m; i++)
        {
            int u= edges[i][0];
            int v= edges[i][1];
            indegree[v]++;
        }
        
        int cnt= 0;
        int champion= -1;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]== 0)
            {
                cnt++;
                champion= i;
            }
          
          // if there are more than one winners, return -1
            if(cnt > 1)
            {
                return -1;
            }
        }

        if(cnt== 0) return -1;
        return champion;
    }
};