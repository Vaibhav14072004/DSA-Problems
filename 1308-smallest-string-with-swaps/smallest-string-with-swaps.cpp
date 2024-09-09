// Approach 1 -> Using Union Find...

//TC= O(alpha) for findParent() function and UnionByRank() function

// Overall TC= O(alpha) + O(2*alpha) + O(m) + O(n* alpha) + O(m) + O(m log m) + O(m)

/*
O(α(m)) ->> Finding the parent of a node using path compression (inverse Ackermann function, very close to constant
O(2 * α(m)) ->> Union operation with union by rank, which is also O(α(m)).
O(m) ->> Initializing the parent and rank arrays for union-find.
O(n * α(m)) ->> Processing the pairs to perform unions.
O(m) ->> Iterating over each element to group them by their ultimate parent.
O(m log m) ->> Sorting the characters within each connected component.
O(m) ->> Rearranging characters in the original string based on sorted components


***** Overall TC= O(n* alpha) + O(m log m) ******
*/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int node)
    {
        // base case
        if(node== parent[node]){
            return node;
        }
        return parent[node]= findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        // find ultimate parent of given nodes...
        int parent_U= findParent(u);
        int parent_V= findParent(v);

        // if u, v already belongs to same component... directly return
        if(parent_U == parent_V){
            return;
        }

        if(rank[parent_U] > rank[parent_V])
        {
            parent[parent_V]= parent_U;
        }

        else if(rank[parent_U] < rank[parent_V])
        {
            parent[parent_U]= parent_V;
        }

        else
        {
            parent[parent_V]= parent_U;
            rank[parent_U]++;
        }
    }
  
    // TC= O(m) + O(n* alpha) + O(m) + O(m log m) + O(m)

    string smallestStringWithSwaps(string str, vector<vector<int>>& pairs){

        // first union from all pairs vectors...
        int m= str.length();
        parent.resize(m);
        rank.resize(m);

        for(int i=0; i<m; i++)
        {
            parent[i]= i;
            rank[i]= 1;
        }

        for(int i=0; i<pairs.size(); i++)
        {
            unionByRank(pairs[i][0], pairs[i][1]);
        }
        
        // unordered map to store -> ultimateParent corresponding to all nodes {int, vector<int>}
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<m; i++)
        {
            int p= findParent(i);
            mp[p].push_back(i);
        }   

    
    // TC= O(M) + O(M log M) + O(M) 
    // we have not multiplied with TC for iterating mp, bcoz we're already considering all elements (m) 

    for(auto it: mp)
    {
        vector<int> indexes= it.second;
        string temp= "";

        for(int j=0; j<indexes.size(); j++)
        {
            temp+= str[indexes[j]];
        }
        
        // sort the string temp lexicographically....
        sort(temp.begin(), temp.end());

        for(int j=0; j<indexes.size(); j++)
        {
            str[indexes[j]]= temp[j];
        }
     }
    return str;
   }
};