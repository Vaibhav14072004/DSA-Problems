// Approach 2 -> Optimised
// There would only be a single lucky no in whole matrix
// (Find max of all minElements from each row)... bcoz it has highest prob of becoming max in its col
// (Find min of all maxElements from each col)... bcoz it has highest prob of becoming min in its row

// TC= O(N*M)

class Solution{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n= matrix.size();    // row
        int m= matrix[0].size(); // col
        
        // find MAX of all minimum elements from each row..
        int maxiROW= INT_MIN;
        for(int row= 0; row<n; row++)
        {
            int minElement= INT_MAX;
            for(int col= 0; col<m; col++)
            {
               minElement= min(minElement, matrix[row][col]);
            }

            // update maximum out of all min elements..
            maxiROW= max(maxiROW, minElement);  
        }

        // Find MIN of all maximum elements from  each col...
        int miniCOL= INT_MAX;
        for(int col= 0; col<m; col++)
        {
            int maxElement= INT_MIN;
           for(int row= 0; row<n; row++)
           {
                maxElement= max(maxElement, matrix[row][col]);
           }

           // update minimum out of all max elements from each col
           miniCOL= min(miniCOL, maxElement);
        }
    
    // if miniCOL== maxROW .. then this element would be Lucky no
       if(miniCOL== maxiROW)
      {
        return {miniCOL};  // return {maxROW};
      }
    
    return {};
  }
};






// Approach 1 -> Brute Force Approach
// TC= O(N*M)

/*

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

*/