class Solution {
    void dfs_size(int node,unordered_map<int,vector<int>> &adj,vector<bool>&vis, int &size){
         vis[node] = 1;
        
        size++; 
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                
                dfs_size(nbr,adj,vis,size);
                
            }
        }
         
    }
    bool dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool>&vis, int &size){

        vis[node] = 1;
        
        if(adj[node].size() != size) return 0;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                
                bool ch = dfs(nbr,adj,vis,size);
                if(!ch)  return 0;
            }
        }
        return 1;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;

        for( auto i : edges){
            
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,0);
        vector<bool> vis_size(n,0);
        vector<bool> dfs_vis(n,0);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                int size = 0 ;
                dfs_size(i,adj,vis_size,size);
                // cout<<size<<" ";
                size--;
                if(dfs(i,adj,vis,size)){
                //    / cout<<i<<" ";
                    ans++;
                } else {
                    dfs_size(i,adj,vis,size);
                }
            }
        }
        return ans;
    }
};