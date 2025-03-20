class Solution {
public:
    /*
    Approach to solving this problem:

    1. Disjoint Set Union (DSU):
        - Implement a `find` function to find the representative (parent) of a set.
        - Implement a `union` function to merge two sets.
    
    2. Initialization:
        - Each node is initially its own parent.
        - Maintain a `cost` array initialized to -1 to store the minimum bitwise AND cost for each connected component.
    
    3. Processing the Edges:
        - Traverse the given edges.
        - Merge components using DSU and update the cost for each component.
    
    4. Processing the Queries:
        - Check if two nodes belong to the same connected component.
        - If they are in different components, return -1.
        - If they are in the same component, return the minimum bitwise AND cost of their component.
    */

    vector<int> parent;

    // Function to find the root parent of a node using path compression
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression for efficiency
    }

    // Function to perform union of two sets (making x the parent of y)
    void unioun(int x, int y) { 
        parent[y] = x; 
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        // Initialize DSU parent array and cost array
        parent.resize(n);
        vector<int> cost(n, -1); // Initialize all costs to -1
        
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is initially its own parent
        }

        // Process each edge to update the DSU and maintain the cost
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Find the parent (representative) of both nodes u and v
            int parent_u = find(u);
            int parent_v = find(v);

            // If they belong to different components, merge them
            if (parent_u != parent_v) {
                unioun(parent_u, parent_v); // Merge the sets
                cost[parent_u] &= cost[parent_v]; // Update cost for the merged component
            }

            // Update the cost for the parent component with the edge weight
            cost[parent_u] &= w;
        }

        vector<int> res;
        // Process each query
        for (auto q : query) {
            int s = q[0];
            int t = q[1];

            // Find the parent (representative) of both nodes
            int parent_s = find(s);
            int parent_t = find(t);

            // Three cases:
            // 1. If the start and end nodes are the same, the cost is 0.
            if (s == t) {
                res.push_back(0);
            }
            // 2. If the nodes belong to different components, return -1.
            else if (parent_s != parent_t) {
                res.push_back(-1);
            }
            // 3. Otherwise, return the cost of their common component.
            else {
                res.push_back(cost[parent_s]);
            }
        }
        return res;
    }
};