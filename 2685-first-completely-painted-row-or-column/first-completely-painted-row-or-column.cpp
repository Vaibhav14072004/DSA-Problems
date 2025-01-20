// Approach 2 ->> Using unordered_map to store index of arr values...
// TC= O[2* (M*N)]
// SC= O(N*M)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int len= arr.size();
        int n= mat.size();  // rows
        int m= mat[0].size(); // cols
        
        // store the index of arr[i], {arr[i],i}
        unordered_map<int,int> mp;
        for(int i=0; i<len; i++)
        {
            mp[arr[i]]= i;
        }
        
        int minEnd= INT_MAX;

        // check each row and find the maxIdx at which entire row gets painted
        for(int i=0; i<n; i++)
        {
            int maxIdx= INT_MIN;
           for(int j=0; j<m; j++)
           {
               maxIdx= max(maxIdx, mp[mat[i][j]]);
           }
           minEnd= min(minEnd, maxIdx);
        }

        // check each col and find maxIdx at which entire column gets painted..
        for(int j=0; j<m; j++)
        {
            int maxIdx= INT_MIN;
            for(int i=0; i<n; i++)
            {
                maxIdx= max(maxIdx, mp[mat[i][j]]);
            }
            minEnd= min(minEnd, maxIdx);
        }
    return minEnd; 
    }
};






// Approach 1 -> Using Unordered_map to store the {row,col} for particular value
// TC= O(M*N) + O(len)
// Sc= O(M*N) + O(M+N)

/*

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

            // if any row or col becomes full, return i immediately..
            if(rows[currRow]== m || cols[currCol]== n)
            {
                return i;
            }
        }
       return -1;
    }
};

*/