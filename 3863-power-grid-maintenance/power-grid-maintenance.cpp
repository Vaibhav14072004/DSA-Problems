class DSU{
    public:
    vector<int> par,size;
    DSU(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int findUPar(int node){
        if(par[node]==node) return node;
        return par[node] = findUPar(par[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if(up_u==up_v) return;
        else if(size[up_u]<size[up_v]){
            par[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            par[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};
class Solution {
public:
     unordered_map<int,set<int>> ump;
     void dfs(int node,vector<vector<int>>& adj, int up,vector<int>& vis){
        vis[node] = 1;
        ump[up].insert(node);
        for(auto &neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,up,vis);
            }
        }
     }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU ds(c+1);
        vector<vector<int>> adj(c+1);
        for(auto &it:connections){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(c+1,0);
        for(int i=1;i<=c;i++){
            if(!vis[i]){
                int up = ds.findUPar(i);
                dfs(i,adj,up,vis);
            }
        }
   
        vector<int> ans;
        for(auto &it: queries){
            int op = it[0];
            int node = it[1];
           int up = ds.findUPar(node);
            if(op==2){
        
                if(ump[up].find(node)!=ump[up].end()){
                    ump[up].erase(node);
                }
            } else {
                if(ump[up].size()>0){
                   if(ump[up].find(node)!=ump[up].end()){
                    ans.push_back(node);
                   } else {
                    auto it = ump[up].begin();
                    ans.push_back(*it);
                   }
                } else {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};