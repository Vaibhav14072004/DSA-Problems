class Solution {
private:
    vector<int> parent, size;
    
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void  merge(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(par_u == par_v) return;
        if(size[par_u] < size[par_v]){
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        parent.resize(V+1);
        size.resize(V+1);

        for(int i = 1; i <= V; i++){
            parent[i] = i;
        }
        
        for(auto it: edges){
            if(findParent(it[0]) == findParent(it[1])) return {it[0], it[1]};
            else merge(it[0], it[1]);
        }
        return {-1, -1};
    }
};