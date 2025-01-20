// Approach 1 -> Using Unordered_map to store the {row,col} for particular value
// TC= O(M*N) + O(len)
// Sc= O(M*N) + O(M+N)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int len= arr.size();
        int n= mat.size();  // rows
        int m= mat[0].size(); // cols
        
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        
        // store the row and col corresponding to each value..
        unordered_map<int,pair<int,int>> mp;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mp[mat[i][j]]= {i,j};
            }
        }

        for(int i=0; i<len; i++)
        {
            int currRow= mp[arr[i]].first;
            int currCol= mp[arr[i]].second;

            rows[currRow]++;
            cols[currCol]++;
            if(rows[currRow]== m || cols[currCol]== n)
            {
                return i;
            }
        }
       return -1;
    }
};