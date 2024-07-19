// TC= O(N*M)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n= matrix.size();    // row
        int m= matrix[0].size(); // col
        
        vector<int> rowMin(n);
        vector<int> colMax(m);
        
        // find min element for each row..
        for(int row=0; row<n; row++)
        {
            int minElement= INT_MAX;
            for(int col= 0; col<m; col++)
            {
               minElement= min(minElement, matrix[row][col]);
            }
            rowMin[row]= minElement;
        }

        // find max element for each column..
        for(int col= 0; col <m; col++)
        {
            int maxElement= INT_MIN;
            for(int row= 0; row< n; row++)
            {
               maxElement= max(maxElement, matrix[row][col]);
            }
            colMax[col]= maxElement; 
        }
        
        unordered_set<int> st(rowMin.begin(), rowMin.end());
        vector<int> ans;

        for(int k= 0; k<colMax.size(); k++)
        {
            if(st.find(colMax[k]) != st.end())
            {
                 ans.push_back(colMax[k]);
            }
        }
    return ans;
    }
};