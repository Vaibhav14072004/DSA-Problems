// Approach 1 -> Disjoint Set Union....

// TC= O(N^2 * alpha) where alpha is TC of unionByRank
// TC= O(N^2)

/*
Intuition ->> Merge all stones that lie in same column or row into one 
          component.... In every component, we can only remove (elements -1)

        Ans= (n1-1) + (n2-1) + (n3-1) + ...
    ->> (n1 + n2 + n3 + ....) - (1+ 1 + 1 + ...)

    ->> Ans= n - (no of components) where n is no of total stones...
*/


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find_ultimateParent(int node)
    {
        if(node== parent[node])
        {
            return node;
        }
        return parent[node]= find_ultimateParent(parent[node]);
    }


    void unionByRank(int u, int v)
    {
        int ulp_u= find_ultimateParent(u);
        int ulp_v= find_ultimateParent(v);
        
        // if ultimate parent of both nodes are same... do not perform union
        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]= ulp_u;
        }

        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]= ulp_v;
        }

        else{
           parent[ulp_v]= ulp_u;
           rank[ulp_u]++;
        }
    }


    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();

        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++)
        {
            parent[i]= i;
            rank[i]= 0;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                // if they become to same row or same column, union them...
                if(stones[i][0]== stones[j][0] || stones[i][1]== stones[j][1])
                {
                    unionByRank(i,j);
                }
            }
        }

        // now check how many diff components are there, 
        int groups= 0;
        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
            {
                groups++;
            }
        }

        return n- groups;
    }
};


