// Approach 2 -> Best Approach (Calculating prefix xor array)...
// TC= O(M+N)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n= arr.size();
        vector<int> prefXOR(n);
        prefXOR[0]= arr[0];

        for(int i=1; i<n; i++)
        {
            prefXOR[i]= prefXOR[i-1]^arr[i];
        }

        int m= queries.size();
        vector<int> ans(m);

        for(int i=0; i<m; i++)
        {
            int left= queries[i][0];
            int right= queries[i][1];
           
           // same terms on taking xor will cancel each other...
           if(left== 0)
           {
              ans[i]= prefXOR[right];
           }

           else
           {
              ans[i]= prefXOR[left-1] ^ prefXOR[right];
           }
        }
       return ans; 
    }
};







// Approach 1 -> Brute Force Approach
// TC= O(N*M)

/*

class Solution{
 public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        vector<int> vec;

       for(int i=0; i<queries.size(); i++)
       {
           int left= queries[i][0];
           int right= queries[i][1];
           int ans= 0;

           for(int j=left; j<= right; j++)
           {
              ans= ans^ arr[j];
           }

        vec.push_back(ans);   
       }
      return vec; 
    }
};

*/