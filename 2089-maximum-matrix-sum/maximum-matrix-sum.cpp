// TC= O(N*M)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n= matrix.size();     // rows
        int m= matrix[0].size();  // cols
        
        long long ans= 0,cnt= 0;
        int mini= INT_MAX;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] < 0)
                {
                    cnt++;
                }
                ans+= abs(matrix[i][j]);
                mini= min(mini, abs(matrix[i][j]));
            }
        }

        if(cnt % 2 == 0)
        {
           return ans;
        }

        return ans- 2* mini;
    }
};